// 0-1 KnapSack Equal Sum Partition Problem

#include <iostream>
using namespace std;

bool subsetsum(int arr[], int sum, int n)
{
    bool t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < sum + 1; ++j) // Initialisation (base case)
        {
            if (i == 0)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < sum + 1; ++j)
        {
            if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

bool Equal_Sum_Partition(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; ++i) // Calculate sum of the elements in array
        sum += arr[i];

    if (sum & 1) // sum odd cannot have twoequal subsets
        return false;

    // Find if there is subset with sum equal to half of total sum
    return subsetsum(arr, sum / 2, n);
}

int main()
{
    int arr[] = {6, 2, 3, 1, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (Equal_Sum_Partition(arr, n) == true)
        cout << "Can be divided into two subsets of equal sum";
    else
        cout << "Can not be divided into two subsets of equal sum";

    return 0;
}