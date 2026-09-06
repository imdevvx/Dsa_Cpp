#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
Given an array nums of n integers,
return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

To solve Two Sum, 3Sum, 4Sum,
and the generic n-Sum problems on LeetCode,
the standard efficient approach relies on a combination of sorting and the two-pointer technique

To solve 3Sum, you fix one number and run a 2-Sum on the remaining numbers.
To solve 4Sum, you fix two numbers and run a 2-Sum on the remaining numbers.
For N-Sum, you use recursion to fix N-2 numbers using loops,
leaving the final 2 numbers to be solved by the two-pointer approach
*/

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    if (nums.empty() || nums.size() < 4)
        return {};

    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> result;

    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int first = nums[i];

        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int second = nums[j];
            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                long long sum = first + second + nums[left] + nums[right];

                if (sum == target)
                {
                    result.push_back({first, second, nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        right--;
                    }

                    left++;
                    right--;
                }

                else if (sum < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    auto result = fourSum(nums, target);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}