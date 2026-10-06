#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// kadane's algorithm

int maxSubArraySum(vector<int> nums)
{
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

// Best time to buy sell stock can also be done using this approach