#include <iostream>
#include <vector>
using namespace std;

// You are given an array nums with n objects colored red, white, or blue, 
// sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

/* Dutch national flag algorithm */
// Dutch National Flag (DNF) algorithm is an efficient linear-time sorting algorithm designed by Edsger Dijkstra 
// to segregate an array containing three distinct elements into three separate, contiguous groups.

void sortColors(vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0) // swap nums[low] and nums[mid]
        {
            swap(nums[low], nums[mid]);
            
            low++;
            mid++;
        }

        else if (nums[mid] == 1) // increment mid
        {
            mid++;
        }

        else // if nums[mid] == 2 swap nums[mid] and nums[high], decrement high
        {
            swap(nums[high], nums[mid]);
            high--; 
        }
    }

    for (int num : nums){
        cout << num << " ";
    }
}

int main()
{
    vector <int> nums = {2, 0, 2, 2, 1, 1, 0, 0, 2};
    sortColors(nums);
    return 0;
}