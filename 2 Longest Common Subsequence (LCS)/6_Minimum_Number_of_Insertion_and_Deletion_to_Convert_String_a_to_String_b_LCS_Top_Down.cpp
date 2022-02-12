// Minimum Number of Insertion and Deletion to Convert String a to String b (LCS Variation) Top Down

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int LCS(string str1, string str2, int m, int n)
{
    int t[m + 1][n + 1]; // matrix for memoization

    string ind = ""; // string for storing longest subsequence

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

    // reverse(ind.begin(), ind.end()); // reverse LCS as we started storing from t[m][n]

    // cout << ind << endl; // printing the lcs

    // find minimum number of deletions and insertions
    return (str1.length() - ind.length()) + (str2.length() - ind.length());
}

int main()
{
    string str1 = "abcdgh";
    string str2 = "abcdfhr";

    int m = str1.length();
    int n = str2.length();

    cout << "Minimum Number of Insertion and Deletion to Convert String a to b " << LCS(str1, str2, m, n);

    return 0;
}