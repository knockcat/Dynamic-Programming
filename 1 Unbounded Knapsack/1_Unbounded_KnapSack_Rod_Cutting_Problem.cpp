// Unbounded KnapSack Rod-Cutting Problem

#include <iostream>
using namespace std;

int cutRod(int price[], int n)
{
    int len[n]; // Creating Rod can be cut into pieces
    for (int i = 0; i < n; ++i)
        len[i] = i + 1;

    int t[n + 1][n + 1]; // creating array of [n+1][n+1] for memoization

    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            if (i == 0 || j == 0) // initialization
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (len[i - 1] <= j)
                t[i][j] = max(price[i - 1] + t[i][j - len[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][n];
}

int main()
{
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};

    int n = sizeof(price) / sizeof(price[0]);

    cout << cutRod(price, n);

    return 0;
}