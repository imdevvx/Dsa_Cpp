#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Given an array nums containing n distinct numbers in the range [0, n], 
// return the only number in the range that is missing from the array.

int missingNumber(vector<int> &nums)
{

    // // Two pointers method
    sort (nums.begin(), nums.end()); // sort the array

    int left = 0;
    int right = nums.size();

    while (left < right)
    {
        if (nums[left] != left)
        {
            return left;
        }
        left ++;
    }
    return right;

    // // Bitwise XOR method
    // int missing = nums.size();
    // for (int i = 0; i < nums.size(); ++i)
    // {
    //     missing ^= i ^ nums[i];
    // }
    // return missing;

    // // Maths formula method
    // int sum = 0;
    // int n = nums.size();
    // for (int i = 0; i < n; i++)
    // {
    //     sum = sum + nums[i];
    // }

    // return (n * (n + 1)) / 2 - sum; // since n and n + 1 are consecutive int, one no. will be always even
}

int main()
{
    vector<int> nums = {0, 1};
    int result = missingNumber(nums);
    cout << result;
    return 0;
}