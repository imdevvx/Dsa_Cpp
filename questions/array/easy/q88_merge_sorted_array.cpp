#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
You are given two integer arrays nums1 and nums2, 
sorted in non-decreasing(ascending) order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, 
but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    // approach 1
    // nums1.resize(m); // remove the placeholder elements
    // for (int x : nums2)
    // {
    //     nums1.push_back(x);
    // }
    // sort(nums1.begin(), nums1.end());
    


    // approach 2
    int nums1Ptr = m;
    int nums2Ptr = n;
    
    for (int i = m; i < m + n; i++)
    {
        nums1[i] = nums2[i - n];
    }
    sort(nums1.begin(), nums1.end());
    

    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         nums1.push_back(nums2[i]); // nums1 = {1, 2, 3, 0, 0, 0, 2, 5, 6}
//     }

//     sort(nums1.begin(), nums1.end()); // nums1 = {0, 0, 0, 1, 2, 2, 3, 5, 6}

//     nums1.erase(nums1.begin(), nums1.begin() + n);
//     // for (int i = 0; i < m + n; i++)
//     // {
//     //     nums1[i] = nums1[i + n];
//     // }
//     // nums1.resize(m + n);

//     for (int i = 0; i < nums1.size(); i++)
//     {
//         cout << nums1[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     vector<int> nums1 = {1, 2, 3, 0, 0, 0};
//     vector<int> nums2 = {2, 5, 6};
//     int m = 3, n = 3;

//     merge(nums1, m, nums2, n);

//     return 0;
// }
