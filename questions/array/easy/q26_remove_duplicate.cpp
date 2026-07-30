#include <iostream>
#include <vector>
using namespace std;

// Given an integer array nums sorted in non-decreasing (ascending) order,
// remove the duplicates in-place such that each unique element appears only once.
// The relative order of the elements should be kept the same.
// After removing duplicates, return the number of unique elements k.

int removeDuplicates(vector<int> &nums);

int main()
{
    vector <int> nums = {1, 1, 2, 3, 4, 5, 5};
    int result = removeDuplicates(nums);
    cout << result;
    return 0;
}

int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int j = 1; // no. 0 will be always unique
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1]) // unique element found
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j; // The total number of unique elements
}
