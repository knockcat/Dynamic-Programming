// Longest Increasing Subsequence
// Memoization

#include <iostream>
#include <vector>
using namespace std;

int LIS(int index, int prev_Index, vector<int> nums, vector<vector<int>> &t, int n)
{
    if (index == n)
        return 0;
    if (t[index][prev_Index + 1] != -1)
        return t[index][prev_Index + 1];
    int len = 0 + LIS(index + 1, prev_Index, nums, t, n);

    if (prev_Index == -1 || nums[index] > nums[prev_Index])
        len = max(len, 1 + LIS(index + 1, index, nums, t, n));

    return t[index][prev_Index + 1] = len;
}

int main()
{
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = nums.size();
    vector<vector<int>> t(n, vector<int>(n + 1, -1));
    cout << "Length of lis is " << LIS(0, -1, nums, t, nums.size()); // index, prev_index, nums, nums.size();
    return 0;
}