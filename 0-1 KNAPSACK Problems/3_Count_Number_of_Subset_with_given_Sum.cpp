// 0-1 KnapSack Equal Count Number Of Subset With Given Sum

#include <iostream>
using namespace std;

int CountSubsetSum(int arr[], int sum, int n)
{
    int t[n + 1][sum + 1];
    // Initializing the matrix
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < sum + 1; ++j)
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
                t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int arr[] = {2, 3, 5, 8, 10};
    int sum = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << CountSubsetSum(arr, sum, n);
    return 0;
}