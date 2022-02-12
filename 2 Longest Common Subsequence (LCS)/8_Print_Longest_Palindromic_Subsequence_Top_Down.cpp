// Print Longest Palindromic Subsequence Top Down

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string LCS(string str1)
{
    string str2 = str1; // initialising str2 with str1

    reverse(str2.begin(), str2.end()); // reversing string for finding Longest Palindromic Subsequence

    string ind = ""; // string for storing palindromic subsequence

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

    int i = m, j = n;

    while (i > 0 && j > 0)
    {
        // If current character in str1 and str2 are same, then
        // current character is part of LCS
        if (str1[i - 1] == str2[j - 1])
        {
            ind.push_back(str1[i - 1]); // Put current character in result
            --i;                        // reduce values of i, j
            --j;
        }

        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (t[i - 1][j] > t[i][j - 1])
            --i;
        else
            --j;
    }

    reverse(ind.begin(), ind.end()); // reverse LCS as we started storing from t[m][n]

    return ind; // Return the lps
}

int main()
{
    string str1 = "bbbab";

    cout << "Longest Palindromic Subsequence " << LCS(str1);

    return 0;
}