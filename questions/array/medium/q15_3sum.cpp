#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
Given an integer array nums,
return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
and nums[i] + nums[j] + nums[k] == 0.
*/

vector<vector<int>> threeSum(vector<int> &nums)
{
    /* Brute force */
    // vector<vector<int>> result;
    // set<vector<int>> s; // set<uniqueTriplets>

    // int n = nums.size();

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             if (nums[i] + nums[j] + nums[k] == 0)
    //             {
    //                 vector<int> triplets = {nums[i], nums[j], nums[k]};
    //                 sort(triplets.begin(), triplets.end());

    //                 if (s.find(triplets) == s.end())
    //                 {
    //                     s.insert(triplets);
    //                     result.push_back(triplets);
    //                 }
    //             }
    //         }
    //     }
    // }

    // return result;

    /* Hash map */
    // a + b + c = 0;
    // b + c = -a;
    // c = -(a + b)
    // set<vector<int>> uniqueTriplets;

    // int n = nums.size();

    // for (int i = 0; i < n; i++)
    // {
    //     int target = -nums[i];
    //     set<int> s;

    //     for (int j = i + 1; j < n; j++)
    //     {
    //         int toFind = target - nums[j];

    //         if (s.find(toFind) != s.end()){
    //             vector <int> trip = {nums[i], nums[j], toFind};
    //             sort(trip.begin(), trip.end());
    //             uniqueTriplets.insert(trip);
    //         }

    //         s.insert(nums[j]);
    //     }
    // }

    // vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());
    // return result;

    /* Two pointer  */
    sort(nums.begin(), nums.end()); 
    vector<vector<int>> result;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        // 1. Skip duplicate values for the 'first' element
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int first = nums[i]; 
        int left = i + 1;    
        int right = n - 1;   

        while (left < right)
        {
            int sum = first + nums[left] + nums[right];

            if (sum == 0)
            {
                result.push_back({first, nums[left], nums[right]});

                // 2. Skip duplicate values for the 'left' element
                while (left < right && nums[left] == nums[left + 1])
                {
                    left++;
                }
                // 3. Skip duplicate values for the 'right' element
                while (left < right && nums[right] == nums[right - 1])
                {
                    right--;
                }

                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto result = threeSum(nums);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}