// Longest Common Subsequence Recursively Memoization (Botton Up)

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int t[1001][1001];

int LCS(string str1, string str2, int m, int n)
{
    // base Condition
    if (m == 0 || n == 0)
        return 0;

    // memoization
    if (t[m][n] != -1)
        return t[m][n];

    if (str1[m - 1] == str2[n - 1])
        return t[m][n] = 1 + LCS(str1, str2, m - 1, n - 1);
    else
        return t[m][n] = max(LCS(str1, str2, m - 1, n), LCS(str1, str2, m, n - 1));
}

int main()
{
    string str1 = "abcdgh";
    string str2 = "abedfhr";

    memset(t, -1, sizeof(t)); // initialise matrix with -1

    int m = str1.length();
    int n = str2.length();

    cout << "Length of LCS is " << LCS(str1, str2, m, n);

    return 0;
}