#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

/*
Given an integer array nums,
return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
and nums[i] + nums[j] + nums[k] == 0.
*/

int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n < 3)
        return 0;

    sort(nums.begin(), nums.end());               
    int closestSum = nums[0] + nums[1] + nums[2]; 

    for (int i = 0; i < n; i++)
    {
        int first = nums[i]; 
        int left = i + 1;    
        int right = n - 1;   

        while (left < right)
        {
            int currentSum = first + nums[left] + nums[right]; // -4
            if (abs(currentSum - target) < abs(closestSum - target))
                closestSum = currentSum;

            if (currentSum < target)
                left++;
            else if (currentSum > target)
                right--;
            else
                return currentSum;
        }
    }

    return closestSum;
}

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    threeSumClosest(nums, 1);

    return 0;
}