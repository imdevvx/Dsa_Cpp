#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

int singleNumber(vector<int> &nums)
{
    // let nums = {4, 1, 2, 1, 2, 4, 3}
    // XOR approach - best
    // Time complexity O(n)
    /*
        ^ is XOR operator
        A number XOR itself is 0
        A number XOR 0 is the number itself

        XOR drops carry 
        ans = 0 ^ 4 = 4
        ans = 4 ^ 1 = 5
        ans = 5 ^ 2 = 7
        ans = 7 ^ 1 = 6
        ans = 6 ^ 2 = 4
    */
    int ans = 0;
    for (int x : nums)
    {
        ans ^= x; // 0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2 ^ 4 ^ 3 => 0 ^ (4 ^ 4) ^ (1 ^ 1) ^ (2 ^ 2) ^ 3 => 0 ^ 0 ^ 0 ^ 0 ^ 3 => 3
    }
    return ans;

    /*
        // Approach two (hash map)
        // Time complexity - O(n), Space complexity - O(n)

        unordered_map<int, int> frequency;
        for (int x : nums)
        {
            frequency[x]++;
        }
        for (const auto &pair : frequency)
        {
            if (pair.second == 1)
            {
                return pair.first;
            }
        }
        return -1; // Fallback: If no single number exists
    */

    /*
        // My approach
        // Time complexity - O(n^2)

        // for (int x : nums)
        // {
        //     int count = 0;
        //     for (int i = 0; i < nums.size(); i++)
        //     {
        //         if (nums[i] == x)
        //         {
        //             count++;
        //         }
        //     }
        //     if (count == 1)
        //     {
        //         return x;
        //     }
        // }
        // return -1; // Fallback: If no single number exists
    */
}

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2, 4, 3};
    int result = singleNumber(nums);
    cout << result;
    return 0;
}