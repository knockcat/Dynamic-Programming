// 0-1 KnapSack subsetsum Problem

#include <iostream>
using namespace std;

bool subsetsum(int arr[], int sum, int n)
{
    bool t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0) // Initialisation (base case)
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= sum)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int arr[] = {10, 3, 12, 5, 11, 9};
    int sum = 8;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subsetsum(arr, sum, n) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}