#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given an integer array nums sorted in non-decreasing order, 
// return an array of the squares of each number sorted in non-decreasing order.

vector<int> sortedSquares(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums[i] * nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
}

int main()
{

    vector<int> nums = {-7, -3, 2, 3, 11};
    auto result = sortedSquares(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}