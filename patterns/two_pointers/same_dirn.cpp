#include <iostream>
#include <vector>
using namespace std;

/* Both pointers move from left to right, but at different speeds or under different conditions. */
// Q. Remove duplicates from a sorted array 'in place'

/*
slow - writes and modifies
fast - reads and scans through array
*/

vector<int> removeDuplicates(vector<int> &nums)
{
    int slow = 1;

    for (int fast = 1; fast < nums.size(); fast++)
    {
        if (nums[fast] != nums[fast - 1])
        {
            nums[slow] = nums[fast];
            slow++;
        }
    }

    return nums;
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 4, 4, 4, 5, 6, 7, 7};
    auto result = removeDuplicates(nums);
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}