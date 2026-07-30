#include <iostream>
#include <vector>
using namespace std;

// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.

vector<int> twoSum(vector<int> &nums, int target);

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;

    vector<int> result = twoSum(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    
    return 0;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {}; // return empty vector if no match is found
}