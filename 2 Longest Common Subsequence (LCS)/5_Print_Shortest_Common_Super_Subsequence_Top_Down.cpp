// Print Shortest Common Super Subsequence Top Down Memoization

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string LCS(string str1, string str2, int m, int n)
{
    int t[m + 1][n + 1]; // matrix for memoization

    string ind = ""; // string for storing longest sebsequence

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
        // if currrent character in str1 and str2 are same, then
        //  current character is part of LCS
        if (str1[i - 1] == str2[j - 1])
        {
            ind.push_back(str1[i - 1]); // Put current character in result
            --i;
            --j; // reduce values of i,j;
        }

        // If current character in str1 and str2 are different
        else if (t[i][j - 1] > t[i - 1][j])
        {

            ind.push_back(str2[j - 1]); // Put current character of str2 in result
            --j;                        // reduce values of j
        }
        else
        {

            ind.push_back(str1[i - 1]); // Put current character of str1 in result
            --i;                        // reduce values of i
        }
    }

    // If str2 reaches its end, put remaining characters
    // of str1 in the result string
    while (i > 0)
    {
        ind.push_back(str1[i - 1]);
        --i;
    }

    // If str1 reaches its end, put remaining characters
    // of str2 in the result string
    while (j > 0)
    {
        ind.push_back(str2[j - 1]);
        --j;
    }

    reverse(ind.begin(), ind.end()); // reverse LCS as we started storing from t[m][n]

    return ind; // Return the LCS
}

int main()
{
    string str1 = "abcdgh";
    string str2 = "abcdfhr";

    int m = str1.length();
    int n = str2.length();

    cout << "Length of Shortest Common Super Subsequence is " << LCS(str1, str2, m, n);

    return 0;
}