// Longest Palindromic Substring TopDown

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LCS(string str1, string str2, int m, int n)
{
    int t[m + 1][n + 1]; // matrix for memoization

    int result = 0; // To store length of the longest Palindromic substring

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
            {
                t[i][j] = 1 + t[i - 1][j - 1];
                result = max(result, t[i][j]);
            }
            else
                t[i][j] = 0;
        }
    }

    return result;
}

int main()
{
    string str1 = "abcbab";
    string str2 = str1;

    reverse(str2.begin(), str2.end());

    int m = str1.length();

    cout << "Length of Longest Palindromic Substring is " << LCS(str1, str2, m, m);

    return 0;
}

