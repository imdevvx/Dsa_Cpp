#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Given an integer array nums where every element appears three times except for one, which appears exactly once. 
// Find the single element and return it.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> freq;

    for (int num : nums)
    {
        freq[num]++;
    }

    for (const auto &pair : freq)
    {
        if (pair.second == 1)
        {
            return pair.first;
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    int result = singleNumber(nums);
    cout << result;
    return 0;
}