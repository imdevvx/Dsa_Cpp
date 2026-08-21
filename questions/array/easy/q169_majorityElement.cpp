#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> frequency;
    for (int x : nums)
    {
        frequency[x]++;
    }

    auto max_it = frequency.begin();
    // since iterator points to an object we use arrows and not .first & .second

    for (auto it = frequency.begin(); it != frequency.end(); it++)
    {
        if (it->second > max_it->second){
            max_it = it;
        }
    }
    return max_it->first;


/*
    // Approach 2 -:
    // unordered_map <int, int> frequency;
    // int maxCount = 0;
    // int mostFrequent = nums[0];

    // for(int x : nums){
    //     frequency[x]++;

    //     if(frequency[x] > maxCount){
    //         maxCount = frequency[x];
    //         mostFrequent = x;
    //     }
    // }
    // return mostFrequent;
*/
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3, 3, 3};
    auto result = majorityElement(nums);
    cout << result;
    return 0;
}