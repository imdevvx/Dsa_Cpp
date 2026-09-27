#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
The pair sum of a pair (a,b) is equal to a + b. 
The maximum pair sum is the largest pair sum in a list of pairs.

For example, if we have pairs (1,5), (2,3), and (4,4), 
the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
Given an array nums of even length n, 
pair up the elements of nums into n / 2 pairs such that:

**Each element of nums is in exactly one pair, and**
**The maximum pair sum is minimized.**

• "Pair sum": Add the two numbers in a pair together. If your pair is (1, 6), the pair sum is 7.
• "Maximum pair sum": Once you have made all your pairs, look at all their sums and find the largest one.
• "is minimized": Your ultimate goal is to arrange the pairs in such a way that this "largest sum" is as small as it possibly can be.

Eg: {1, 2, 3, 4, 5, 6}
Pairs can be: (1, 2) (3, 4) (5, 6) => Max sum = 11
Pairs can be: (1, 3) (2, 4) (5, 6) => Max sum = 11
Pairs them optimally (Smallest + Largest): (1, 6) (2, 5) (3, 4) => Max sum = 7

Return the minimized maximum pair sum after optimally pairing up the elements.
*/

int minPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int max_sum = nums[0] + nums[n - 1];

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int curr_sum = nums[left] + nums[right];
        if (curr_sum > max_sum)
            max_sum = curr_sum;

        left++;
        right--;
    }

    return max_sum;
}

int main()
{
    vector<int> nums = {3, 5, 2, 3};
    int result = minPairSum(nums);

    cout << result;
    return 0;
}