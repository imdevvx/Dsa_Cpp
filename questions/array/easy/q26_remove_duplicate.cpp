#include <iostream>
#include <vector>
using namespace std;

// Given an integer array nums sorted in non-decreasing (ascending) order,
// remove the duplicates in-place such that each unique element appears only once.
// The relative order of the elements should be kept the same.
// After removing duplicates, return the number of unique elements k.

int removeDuplicates(vector<int> &nums)
{
    int insertIndex = 1; // number 0 will be always unique

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1]){
            nums[insertIndex] = nums[i];
            insertIndex++;
        }
    }

    return insertIndex; 
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 4, 5, 5};
    int result = removeDuplicates(nums);
    cout << result;
    return 0;
}