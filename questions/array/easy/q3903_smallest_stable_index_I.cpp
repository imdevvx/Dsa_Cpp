#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
You are given an integer array nums of length n and an integer k.
For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).

In other words:
max(nums[0..i]) is the largest value among the elements from index 0 to index i.
min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
An index i is called stable if its instability score is less than or equal to k.

Return the smallest stable index. If no such index exists, return -1.
*/

int firstStableIndex(vector<int> &nums, int k)
{
    // if (nums.empty())
    //     return -1;

    // vector<int> stableIndexes;
    // int n = nums.size();

    // for (int i = 0; i < n; i++)
    // {
    //     int maxi = nums[0];
    //     int mini = nums[i];
    //     for (int j = 0; j <= i; j++)
    //     {
    //         maxi = max(maxi, nums[j]);
    //     }

    //     for (int k = i; k < n; k++)
    //     {
    //         mini = min(mini, nums[k]);
    //     }

    //     int stableIndex = maxi - mini;

    //     if (stableIndex <= k)
    //     {
    //         stableIndexes.push_back(i);
    //     }
    // }

    // if (stableIndexes.empty())
    //     return -1;

    // int smallestStableIdx = *min_element(stableIndexes.begin(), stableIndexes.end());
    // return smallestStableIdx;

    if (nums.empty())
        return -1;

    int n = nums.size();

    /*
    prefMax — prefix maximum
    A prefix means "everything from the beginning up to this index."

    | index | `nums[i]` | Elements from `0` to `i` | `prefMax[i]` |
    | ----: | --------: | ------------------------ | -----------: |
    |     0 |         3 |  [3]                     |            3 |
    |     1 |         1 |  [3,1]                   |            3 |
    |     2 |         5 |  [3,1,5]                 |            5 |
    |     3 |         2 |  [3,1,5,2]               |            5 |
    |     4 |         4 |  [3,1,5,2,4]             |            5 |

    */
    vector<int> prefMax(n);
    prefMax[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefMax[i] = max(prefMax[i - 1], nums[i]);
    }

    /*
    suffMin — suffix minimum
    A suffix means "everything from this index to the end."
    */
    vector<int> suffMin(n);
    suffMin[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffMin[i] = min(suffMin[i + 1], nums[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (prefMax[i] - suffMin[i] <= k)
        {
            return i; // Found the earliest index, return immediately
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {0};
    int k = 0;

    int result = firstStableIndex(nums, k);
    cout << result;
    return 0;
}