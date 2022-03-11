// Matrix Chain Multiplication Bottom Up Memoization

#include <iostream>
#include <cstring>
using namespace std;

int t[1001][1001];

int MCM(int arr[], int i, int j)
{
    if (i >= j)
        return 0;

    if (t[i][j] != -1)
        return t[i][j];

    int mn = INT_MAX;

    // place parenthesis at different places
    // between first and last matrix, recursively
    // calculate tempans of multiplications for
    // each parenthesis placement and return the
    // minimum tempans
    for (int k = i; k < j; ++k)
    {
        int tempans = MCM(arr, i, k) + MCM(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

        mn = min(tempans, mn);
    }

    return t[i][j] = mn;
}

int main()
{
    // Matrix Ai has dimension p[i-1] x p[i]
    // for i = 1..n
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    memset(t, -1, sizeof(t));

    cout << "Minimum number of multiplications is " << MCM(arr, 1, n - 1);

    return 0;
}