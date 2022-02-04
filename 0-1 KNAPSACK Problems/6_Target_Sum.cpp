// 0-1 KnapSack Target Sum

#include <iostream>
using namespace std;

int CountsubsetSum(int arr[], int sum, int n)
{
    int t[n + 1][sum + 1];

    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < sum + 1; ++j)
        {
            if (i == 0) // initialisation
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
    int arr[] = {0, 1, 2, 10, 9, 8};
    int targetsum = 8;
    int sum = 0;

    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; ++i)
        sum += arr[i];

    sum = (sum + targetsum) / 2; // similar to Count Number Of Subset With Given Difference

    cout << CountsubsetSum(arr, sum, n);

    return 0;
}
