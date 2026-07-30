#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Given a sorted array of distinct integers and a target value,
// return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity. (means binary search)

int searchInsert(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // 4 + (6 - 4) / 2 = 5

        if (target == nums[mid])
            return mid;

        else if (target < nums[mid]) // if target is smaller than num at mid ignore right half
            high = mid - 1; 
        else // if (target > nums[mid]) low = mid + 1; // if target is greater than num at mid ignore left half
        low = mid + 1;
    }
    // low represents the correct insertion index if not found
    return low;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 7, 8};
    int target = 2;
    auto result = searchInsert(nums, target);
    cout << result;
    return 0;
}

/*TIME COMPLEXITY O(n log n) BECAUSE OF THE LOOP (O(n)) ALSO WE ARE MODIFYING OUR ARRAY*/
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;

// // Given a sorted array of distinct integers and a target value,
// // return the index if the target is found.
// // If not, return the index where it would be if it were inserted in order.
// // You must write an algorithm with O(log n) runtime complexity. (means binary search)

// int searchInsert(vector<int> &nums, int target)
// {
//     if (nums.empty())
//     {
//         return 0;
//     }

//     for (int i = 0; i < nums.size(); i++)
//     {
//         // if target is found
//         if (nums[i] == target)
//         {
//             return i;
//         }
//     }

//     // if target not found
//     nums.push_back(target);
//     sort(nums.begin(), nums.end());

//     // find index of target by binary search for time complexity O(log n)
//     int low = 0;
//     int high = nums.size() - 1;

//     while (low <= high)
//     {
//         int mid = (low + high) / 2;
//         if (nums[mid] == target)
//             return mid;
//         if (target < nums[mid]) // if target is smaller ignore right half
//             high = mid - 1;
//         if (target > nums[mid]) // if target is greater ignore left half
//             low = mid + 1;
//     }
// }

// int main()
// {
//     vector<int> nums = {1, 2, 3, 4, 5, 7, 8};
//     int target = 6;
//     auto result = searchInsert(nums, target);
//     cout << result;
//     return 0;
// }