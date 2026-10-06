#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArraySum(vector<int> nums)
{
    // Brute force
    // int maxSum = nums[0];
    // for (int start = 0; start < nums.size(); start++)
    // {
    //     int currSum = 0;
    //     for (int end = start; end < nums.size(); end++)
    //     {
    //         currSum += nums[end];
    //         maxSum = max(currSum, maxSum);
    //     }
    // }

    // kadane's algorithm
    int n = nums.size();
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < n; i++)
    {
        currSum += nums[i];
        maxSum = max(currSum, maxSum);

        if (currSum < 0) currSum = 0;
    }

    return maxSum;

}

int main()
{
    vector<int> nums = {-1, -2, -3, -4, -5};
    int maxSum = maxSubArraySum(nums);
    cout << maxSum;
    return 0;
}