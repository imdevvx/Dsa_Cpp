#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Given an integer array of size n, find all elements that appear more than ⌊n / 3⌋ times.

vector<int> majorityElement(vector<int> &nums)
{
    /* Extended Boyer-Moore Voting Algorithm */

    // Step 1: Find potential candidates
    int cand1 = 0, cand2 = 0;
    int count1 = 0, count2 = 0;

    for (int num : nums)
    {
        if (num == cand1 && count1 > 0)
        {
            count1++;
        }
        else if (num == cand2 && count2 > 0)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            cand1 = num;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            cand2 = num;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // Step 2: Verify the candidates
    int actualCount1 = 0;
    int actualCount2 = 0;

    for (int num : nums)
    {
        if (count1 > 0 && num == cand1)
            actualCount1++;
        else if (count2 > 0 && num == cand2)
            actualCount2++;
    }

    std::vector<int> result;
    int threshold = nums.size() / 3;

    if (count1 > 0 && actualCount1 > threshold)
    {
        result.push_back(cand1);
    }
    if (count2 > 0 && actualCount2 > threshold)
    {
        result.push_back(cand2);
    }

    return result;

    // int n = nums.size();
    // int should_appear = n / 3; // Note (7 / 3) = 2 (The result is rounded toward zero)

    // vector<int> result;

    // unordered_map<int, int> freq;
    // for (const int &num : nums)
    // {
    //     freq[num]++;
    // }
    // for (const auto &pair : freq)
    // {
    //     if (pair.second > should_appear)
    //     {
    //         result.push_back(pair.first);
    //     }
    // }

    // return result;
}

int main()
{
    vector<int> nums = {1};
    vector<int> result = majorityElement(nums);
    for (const int &num : result)
    {
        cout << num << " ";
    }
    return 0;
}