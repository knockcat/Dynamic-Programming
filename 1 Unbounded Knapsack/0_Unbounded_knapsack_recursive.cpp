// Unbounded KnapSack Recursively with Memoization

#include <iostream>
#include <cstring>
using namespace std;
int t[102][1002];

int unknapSack(int wt[], int val[], int w, int n)
{
    if (n == 0 || w == 0) // base case
        return 0;

    if (t[n][w] != -1) // memoization
        return t[n][w];

    if (wt[n - 1] <= w)
        return t[n][w] = max(val[n - 1] + unknapSack(wt, val, w - wt[n - 1], n), unknapSack(wt, val, w, n - 1));

    return t[n][w] = unknapSack(wt, val, w, n - 1);
}

int main()
{
    memset(t, -1, sizeof(t)); // initialise matrix with -1

    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};

    int W = 100;

    int n = sizeof(val) / sizeof(val[0]);

    cout << unknapSack(wt, val, W, n);

    return 0;
}