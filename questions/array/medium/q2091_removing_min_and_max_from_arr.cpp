#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/*
You are given a 0-indexed array of distinct integers nums.

There is an element in nums that has the lowest value and an element that has the highest value.
We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.

A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.
Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.
*/

int minimumDeletions(vector<int> &nums)
{
    if (nums.empty())
        return -1;

    int size = nums.size();

    // minimum and maximum number
    auto min_it = min_element(nums.begin(), nums.end());
    auto max_it = max_element(nums.begin(), nums.end());

    // index of minimum and maximum number
    int minIdx = distance(nums.begin(), min_it);
    int maxIdx = distance(nums.begin(), max_it);

    // index of minimum and maximum number from back
    int minIdx_back = size - 1 - minIdx;
    int maxIdx_back = size - 1 - maxIdx;

    // Remove both from front
    int case1 = max(minIdx, maxIdx) + 1;

    // Remove both from back
    int case2 = max(minIdx_back, maxIdx_back) + 1;

    // Remove min from front and max from back
    int case3 = (minIdx + 1) + (maxIdx_back + 1);

    // Remove max from front and min from back
    int case4 = (maxIdx + 1) + (minIdx_back + 1);

    return min({case1, case2, case3, case4});
}

int main()
{
    vector<int> nums = {0, -4, 19, 1, 8, -2, -3, 5};
    int result = minimumDeletions(nums);
    cout << result;
    return 0;
}
