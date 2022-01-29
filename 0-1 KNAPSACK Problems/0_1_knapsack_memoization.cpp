// Recursive Implementation of 0-1 KnapSack Problem with Memoization

#include <iostream>
#include <cstring>
using namespace std;
int t[100][1002];

int KnapSack(int wt[], int val[], int W, int n)
{
    // base Condition
    if (n == 0 || W == 0)
        return 0;

    if (t[n][W] != -1) // memoization
        return t[n][W];

    // nth item included or not included
    if (wt[n - 1] <= W)
    {
        return t[n][W] = max((val[n - 1] + KnapSack(wt, val, W - wt[n - 1], n - 1)), KnapSack(wt, val, W, n - 1));
    }

    // if wt is more item cannot be included
    return t[n][W] = KnapSack(wt, val, W, n - 1);
}

int main()
{
    memset(t, -1, sizeof(t)); // initialise matrix with -1
    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};

    int W = 50;

    int n = sizeof(val) / sizeof(val[0]);

    cout << KnapSack(wt, val, W, n);

    return 0;
}