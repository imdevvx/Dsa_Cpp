#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Given an integer array nums, 
// return true if any value appears at least twice in the array, 
// and return false if every element is distinct.

bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> freq;
    bool appears = false;

    for(int num : nums){
        freq[num]++;
    }
    for (const auto &pair: freq)
    {
        if(pair.second > 1){
            appears = true;
            break;
        }
    }
    return appears;
}

int main()
{
    vector<int> nums = {1, 2, 1, 3, 4};
    auto result = containsDuplicate(nums);
    cout << (result? "true" : "false");
    return 0;
}