#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Given an integer array nums and an integer k, 
return the smallest positive multiple of k that is missing from nums.
A multiple of k is any positive integer divisible by k.
*/

int missingMultiple(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end()); // [2, 3, 4, 6, 8]
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int miss_multiple = k;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % k != 0)
        {
            continue;
        }
        if (nums[i] != miss_multiple)
        {
            return miss_multiple;
        }
        miss_multiple += k;
    }
    return miss_multiple;



    /* Ai approach */
    // unordered_set<int> multiples;
    // for (int num : nums)
    // {
    //     if (num % k == 0)
    //     {
    //         multiples.insert(num);
    //     }
    // }

    // int miss_multiple = k;
    // while (multiples.count(miss_multiple))
    // {
    //     miss_multiple += k;
    // }

    // return miss_multiple;
}

int main()
{
    vector<int> nums = {8, 2, 3, 4, 6};
    int result = missingMultiple(nums, 2);
    cout << result;
    return 0;
}