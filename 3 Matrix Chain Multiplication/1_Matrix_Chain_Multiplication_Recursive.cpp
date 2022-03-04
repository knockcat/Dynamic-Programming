// Matrix Chain Multiplication Recursive

#include <iostream>
using namespace std;

int MCM(int arr[], int i, int j)
{
    if (i >= j)
        return 0;

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

    return mn;
}

int main()
{
    // Matrix Ai has dimension p[i-1] x p[i]
    // for i = 1..n
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is " << MCM(arr, 1, n - 1);

    return 0;
}