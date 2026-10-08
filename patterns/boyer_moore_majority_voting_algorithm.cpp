#include <iostream>
#include <vector>
using namespace std;

int findMajorityElement(vector<int> &nums)
{
    int candidate = 0;
    int count = 0;

    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num;
            count = 1;
        }
        else if (num == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int actualCount = 0;
    for (int num : nums)
    {
        if (num == candidate)
        {
            actualCount++;
        }
    }

    if (actualCount > nums.size() / 2)
    {
        return candidate;
    }

    return -1;
}

int main()
{
    std::vector<int> numbers = {2, 2, 1, 1, 1, 2, 2};

    int result = findMajorityElement(numbers);

    if (result != -1)
    {
        std::cout << "The majority element is: " << result << std::endl;
    }
    else
    {
        std::cout << "No majority element found." << std::endl;
    }

    return 0;
}

/*
• To find elements appearing > n/2, you track at most 1 candidate (Standard Boyer-Moore).
• To find elements appearing > n/3, you track at most 2 candidates.
• To find elements appearing > n/k, you track at most \(k - 1\) candidates.





Given an integer array of size n, 
find all elements that appear more than ⌊n / 3⌋ times.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector <int> result;

        int candidate1 = 0;
        int candidate2 = 0;
        int count1 = 0;
        int count2 = 0;

        for (const int &x : nums) {
            if (x == candidate1) {
                count1++;
            } else if (x == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = x;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = x;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        int actualCount1 = 0;
        int actualCount2 = 0;
        for (const int &x: nums){
            if (x == candidate1) actualCount1++;
            else if (x == candidate2) actualCount2++;
        }

        int n = nums.size();
        if (actualCount1 > n / 3) result.push_back(candidate1);
        if (actualCount2 > n / 3) result.push_back(candidate2);

        return result;
    }
};
*/