#include <iostream>
#include <vector>
using namespace std;

/*
Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
*/

vector<int> searchRange(vector<int> &nums, int target)
{
    if (nums.empty())
        return {-1, -1};

    vector<int> result;

    int left = 0;
    int right = nums.size() - 1;
    int first_idx = -1;

    // search first occurrence of target
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (target == nums[mid])
        {
            first_idx = mid;
            right = mid - 1;
        }
        else if (target < nums[mid])
        {
            right = mid - 1; // search left half
        }
        else
        {
            left = mid + 1; // search right half
        }
    }

    if (first_idx == -1)
    {
        return {-1, -1};
    }

    int low = 0;
    int high = nums.size() - 1;
    int second_idx = -1;

    // search second occurrence of target
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (target == nums[mid])
        {
            second_idx = mid;
            low = mid + 1;
        }
        else if (target < nums[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    result.push_back(first_idx);
    result.push_back(second_idx);

    return result;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10, 12};
    auto result = searchRange(nums, 8);
    for (int &num : result)
    {
        cout << num << " ";
    }
    return 0;
}
