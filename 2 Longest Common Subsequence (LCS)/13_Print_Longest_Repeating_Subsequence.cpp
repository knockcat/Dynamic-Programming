// Print Longest Repeating Subsequence Top Down

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string LCS(string str1)
{
    string str2 = str1; // initialising str2 with str1

    int m = str1.length(); // length of str1
    int n = str2.length(); // length of str2

    string ind = ""; // string for storing longest repeating sebsequence

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
            // If characters match and indexes are
            // not same
            if (str1[i - 1] == str2[j - 1] && i != j)
                t[i][j] = 1 + t[i - 1][j - 1];
            else
                // If characters do not match
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }

    int i = m, j = n;

    while (i > 0 && j > 0)
    {
        // If this cell is same as diagonally
        // adjacent cell just above it, then
        // same characters are present at
        // str1[i-1] and str2[j-1]. Append any
        // of them to result.
        if (t[i][j] == t[i - 1][j - 1] + 1)
        {
            ind.push_back(str1[i - 1]); // Put current character in result
            --i;                        // reduce values of i, j
            --j;
        }

        // Otherwise we move to the side
        // that that gave us maximum result
        else if (t[i][j] = t[i][j])
            --i;
        else
            --j;
    }
    reverse(ind.begin(), ind.end()); // reverse LCS as we started storing from t[m][n]

    return ind; // Return the longes repeating subsequence
}

int main()
{
    string str1 = "AABEBCDD";

    cout << "The length of the largest subsequence that repeats itself is : " << LCS(str1);

    return 0;
}