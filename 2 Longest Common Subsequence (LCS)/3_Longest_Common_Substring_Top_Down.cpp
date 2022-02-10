// Longest Common Substring Top Down Memoization

#include <iostream>
#include <string>
using namespace std;

int LCS(string str1, string str2, int m, int n)
{
    int t[m + 1][n + 1]; // matrix for memoization

    int result = 0; // To store length of thelongest common substring

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
    string str1 = "abcdgh";
    string str2 = "abcdfhr";

    int m = str1.length();
    int n = str2.length();

    cout << "Length of Longest Common Substring is " << LCS(str1, str2, m, n);

    return 0;
}