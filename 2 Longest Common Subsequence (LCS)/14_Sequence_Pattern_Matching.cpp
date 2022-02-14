// Sequence Pattern Matching Top Down

#include <iostream>
#include <string>
using namespace std;

bool LCS(string str1, string str2, int m, int n)
{
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

    // either a is the subsequence of b or viceversa
    // LCS is equal to either a or b
    return t[m][n] == min(m, n);
}

int main()
{
    string str1 = "AXY";
    string str2 = "ADXCPY";

    int m = str1.length();
    int n = str2.length();

    if (LCS(str1, str2, m, n))
        cout << "Pattern Matched " << endl;
    else
        cout << "Pattern Not Matched " << endl;

    return 0;
}