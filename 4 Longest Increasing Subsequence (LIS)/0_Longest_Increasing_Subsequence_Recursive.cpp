// Longest Increasing Subsequence
// Recursive

#include <iostream>
#include <vector>
using namespace std;

int LIS(int index, int prev_Index, vector<int> nums, int n)
{
    if (index == n)
        return 0;

    int len = 0 + LIS(index + 1, prev_Index, nums, n);

    if (prev_Index == -1 || nums[index] > nums[prev_Index])
        len = max(len, 1 + LIS(index + 1, index, nums, n));

    return len;
}

int main()
{
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = nums.size();
    cout << "Length of lis is " << LIS(0, -1, nums, nums.size()); // index, prev_index, nums, nums.size();
    return 0;
}