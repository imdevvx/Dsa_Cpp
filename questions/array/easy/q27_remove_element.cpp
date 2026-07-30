#include <iostream>
#include <vector>
using namespace std;

// Given an integer array nums and an integer val, 
// remove all occurrences of val in nums in-place. 
// The order of the elements may be changed. 
// Then return the number of elements in nums which are not equal to val.

int removeElement(vector<int> &nums, int val)
{
    if (nums.empty())
        return 0;
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[j] = nums[i]; // left shift
            j++;
        }
    }
    return j; // the number of elements in nums which are not equal to val
}

int main()
{
    vector <int> nums = {0, 0, 1, 2, 2, 2, 2, 3, 4, 4};
    int val = 2;
    int result = removeElement(nums, val);
    cout << result;
    return 0;
}