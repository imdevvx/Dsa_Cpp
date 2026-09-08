#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

/*
Given two integer arrays nums1 and nums2,
return an array of their intersection.
Each element in the result must be unique
and you may return the result in any order.
*/

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    /* Method 1 */
    // vector<int> result;
    // for (const int &x : nums1)
    // {
    //     auto itt = find(result.begin(), result.end(), x);
    //     if (itt != result.end())
    //         continue;

    //     auto it = find(nums2.begin(), nums2.end(), x);

    //     if (it != nums2.end())
    //     {
    //         result.push_back(x);
    //     }
    // }
    // return result;

    /* Method 2 */
    // vector<int> result;

    // set<int> s1;
    // set<int> s2;

    // for (const int &x : nums1)
    // {
    //     s1.insert(x);
    // }
    // for (const int &x : nums2)
    // {
    //     s2.insert(x);
    // }

    // for (const int &num : s2)
    // {
    //     if (s1.find(num) != s1.end())
    //     {
    //         result.push_back(num);
    //     }
    // }

    // return result;

    /* Method 3 */
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> result;

    for (const int &num : nums2)
    {
        if (s1.find(num) != s1.end())
        {
            result.insert(num);
        }
    }

    return vector<int>(result.begin(), result.end());
}
int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    auto result = intersection(nums1, nums2);

    for (const int &x : result)
    {
        cout << x << " ";
    }
    return 0;
}