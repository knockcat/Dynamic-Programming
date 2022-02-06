// Unbounded KnapSack Top - Down Approach

#include <iostream>
using namespace std;

int unknapSack(int wt[], int val[], int w, int n)
{
    int t[n + 1][w + 1]; // creating array of [n+1][w+1]

    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < w + 1; ++j)
        {
            if (i == 0 || j == 0) // initialization
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < w + 1; ++j)
        {
            if (wt[i - 1] <= j)
                t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][w];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};

    int W = 50;

    int n = sizeof(val) / sizeof(val[0]);

    cout << unknapSack(wt, val, W, n);

    return 0;
}