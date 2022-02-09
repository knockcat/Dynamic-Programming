// Longest Common Subsequence Recursively

#include <iostream>
#include <string>
using namespace std;

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int LCS(string str1, string str2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (str1[m - 1] == str2[n - 1])
        return 1 + LCS(str1, str2, m - 1, n - 1);
    else
        return max(LCS(str1, str2, m - 1, n), LCS(str1, str2, m, n - 1));
}

int main()
{
    string str1 = "abcdgh";
    string str2 = "abedfhr";

    int m = str1.length();
    int n = str2.length();

    cout << "Length of LCS is " << LCS(str1, str2, m, n);

    return 0;
}