#include <iostream>
#include <vector>
using namespace std;

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