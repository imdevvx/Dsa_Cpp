#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Given an integer array nums and an integer k, 
// return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    // Approach 1
    unordered_map<int, int> mp;
    int index = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        // have we seen the number before?
        if (mp.find(nums[i]) != mp.end())
        {
            if (i - mp[nums[i]] <= k)
                return true;
        }

        // store/update the most recent index
        mp[nums[i]] = i;
    }

    return false;


    // Approach 2
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = i + 1; j <= i + k && j < nums.size(); j++)
    //     {
    //         if (nums[i] == nums[j]){
    //             return true;
    //         }
    //     }
    // }

    // return false;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    bool result = containsNearbyDuplicate(nums, 3);
    cout << (result? "true": "false");
    return 0;
}