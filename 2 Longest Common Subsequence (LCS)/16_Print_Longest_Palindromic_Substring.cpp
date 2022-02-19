// Print Longest Palindromic Substring Top Down

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string LCS(string str1, string str2, int m, int n)
{
    int t[m + 1][n + 1]; // matrix for memoization

    string ind = ""; // string for storing Longest Palindromic substring

    // To store length of the longest common substring
    // To store the index of the cell which contains the
    // maximum value. This cell's index helps in building
    // up the longest Palindromic substring from right to left.
    int row, col, len = 0;

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
                if (len < t[i][j])
                {
                    len = t[i][j];
                    row = i;
                    col = j;
                }
            }
            else
                t[i][j] = 0;
        }
    }

    // if true, then no common substring exists
    if (len == 0)
        cout << "No Common Substring" << endl;

    // traverse up diagonally form the (row, col) cell
    // until t[row][col] != 0
    while (t[row][col] != 0)
    {
        ind.push_back(str1[row - 1]); // or str2[col-1]

        // move diagonally up to previous cell
        --row;
        --col;
    }

    reverse(ind.begin(), ind.end());

    // required longest palindromic substring
    return ind;
}

int main()
{
    string str1 = "KNOONKNOCKCAT";
    string str2 = str1;

    reverse(str2.begin(), str2.end());

    int m = str1.length();

    cout << "Longest Palindromic Substring is " << LCS(str1, str2, m, m);

    return 0;
}
