// Longest Repeating Subsequence Top Down

#include <iostream>
#include <string>
using namespace std;

int LCS(string str1)
{
    string str2 = str1; // initialising str2 with str1

    int m = str1.length(); // length of str1
    int n = str2.length(); // length of str2

    int t[m + 1][n + 1]; // matrix for memoization

    for (int i = 0; i < m + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < m + 1; ++i)
    {
        for (int j = 1; j < n + 1; ++j)
        {
            // If characters match and indexes are
            // not same
            if (str1[i - 1] == str2[j - 1] && i != j)
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                // If characters do not match
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    return t[n][m]; // longest palindrome subsequence
}

int main()
{
    string str1 = "AABEBCDD";

    cout << "The length of the largest subsequence that repeats itself is : " << LCS(str1);

    return 0;
}