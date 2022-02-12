// Longest Palindromic Subsequence Top Down

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LCS(string str1)
{
    string str2 = str1; // initialising str2 with str1

    reverse(str2.begin(), str2.end()); // reversing string for finding Longest Palindromic Subsequence

    int m = str1.length(); // length of str1
    int n = str2.length(); // length of str2

    int t[m + 1][n + 1]; // matrix for memoization

    for (int i = 0; i < m + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            if (i == 0 || j == 0) // initialising first row and first column to zero
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < m + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            if (str1[i - 1] == str2[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    return t[n][m]; // return LPS
}

int main()
{
    string str1 = "bbbab";

    cout << "Longest Palindromic Subsequence " << LCS(str1);

    return 0;
}