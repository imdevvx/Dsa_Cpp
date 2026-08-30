#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int thirdMax(vector<int> &nums)
{
    /* Approach 1 */
    // // set in descending order
    // set <int, greater<int>> numss;
    // for (const int &n: nums){
    //     numss.insert(n);
    // }

    // if (numss.size() < 3 && !numss.empty()){
    //     int max = *numss.begin(); // since set is in descending order 1st
    //     elem is the max elem return max;
    // }

    // int count = 1;
    // for(const int &n : numss){
    //     if (count == 3){
    //         return n;
    //     }
    //     count ++;
    // }

    // if (!numss.empty()) {
    //     return *numss.begin();
    // }
    // return -1;




    /* Approach 2 */
    // sort nums in descending order
    // sort(nums.begin(), nums.end(), greater<int>());
    // // unique returs an iterator to the first duplicate elem, after pushing all the unique elem to the front
    // nums.erase(unique(nums.begin(), nums.end()), nums.end());

    // if (nums.size() < 3)
    // {
    //     return nums[0];
    // }
    // return nums[2];





    /* Approach 3 */
    set<int> firstThree;

    for (const int &n : nums)
    {
        firstThree.insert(n);
        if (firstThree.size() > 3)
        {
            firstThree.erase(firstThree.begin());
        }
    }

    if (firstThree.size() == 3){
        return *firstThree.begin();
    }

    return *firstThree.rbegin();
}

int main()
{
    vector<int> nums = {3, 2, 1};
    int result = thirdMax(nums);
    return 0;
}