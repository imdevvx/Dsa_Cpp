#include <iostream>
#include <vector>
using namespace std;

/*
Binary search is an efficient algorithm
used to find the position of a target value within a sorted array
by repeatedly dividing the search interval in half.
*/

int getIndex(vector<int> nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (target == nums[mid])
            return mid;
        else if (target > nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1; // if no index is found
}

int main()
{
    vector<int> nums = {3, 6, 7, 9, 19, 23, 109}; // sorted array
    int target = 23;
    auto result = getIndex(nums, target);
    cout << "target found at index: " << result;
    return 0;
}