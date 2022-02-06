// Unbounded KnapSack Coin Change I Maximum Number of Ways

#include <iostream>
using namespace std;

int CoinChange(int coins[], int sum, int n)
{
    int t[n + 1][sum + 1]; // creating array of [n+1][sum+1] for memoization

    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < sum + 1; ++j)
        {
            if (i == 0) // initialization
                t[i][j] = 0;
            if (j == 0)
                t[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < sum + 1; ++j)
        {
            if (coins[i - 1] <= j)
                t[i][j] = t[i - 1][j] + t[i][j - coins[i - 1]];
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}

int main()
{
    int coins[] = {1, 2, 3}; // array of coins

    int sum = 5; // sum to be made

    int n = sizeof(coins) / sizeof(coins[0]);

    cout << "Number of possible ways in which " << sum << " can be made is " << CoinChange(coins, sum, n) << endl;
    return 0;
}