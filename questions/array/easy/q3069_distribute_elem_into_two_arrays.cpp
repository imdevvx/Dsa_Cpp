#include <iostream>
#include <vector>
using namespace std;

/*
You are given a 1-indexed array of distinct integers nums of length n.

You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. 
In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. Afterwards, in the ith operation:

If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. Otherwise, append nums[i] to arr2.
The array result is formed by concatenating the arrays arr1 and arr2. 
For example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result = [1,2,3,4,5,6].

Return the array result.
*/

vector<int> resultArray(vector<int> &nums)
{
    int size = nums.size();
    vector<int> arr1;
    vector<int> arr2;

    // 1st two operation
    if (size >= 2)
    {
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
    }

    // Instead of i and j we can simply use vec.back() to get the last element of vector
    int k = 0; // 0 and 1 => 1
    int i = 0; // => 1
    int j = 0;
    while (k < size - 2)
    {
        if (arr1[i] > arr2[j])
        {
            arr1.push_back(nums[k + 2]);
            i++;
        }
        else
        {
            arr2.push_back(nums[k + 2]);
            j++;
        }
        k++;
    }

    vector<int> result = arr1; // copy arr1 elements
    result.reserve(arr1.size() + arr2.size());
    result.insert(result.end(), arr2.begin(), arr2.end()); // pos, it1, it2

    return result;
}

int main()
{
    cout << "Hello world.." << endl;
    vector<int> nums = {1, 2, 3, 0, 5, 7};
    auto result = resultArray(nums);

    for (int &num : result)
    {
        cout << num << " ";
    }

    return 0;
}