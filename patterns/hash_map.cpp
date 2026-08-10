#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
The hash map approach is a programming technique that stores data in key-value pairs
and uses a hash function to find values instantly.
Key features include fast lookups, unique keys, and constant average time
*/

vector<int> frequency(vector<int> &nums)
{
    unordered_map<int, int> freq;

    for (int i = 0; i < nums.size(); i++)
    {
        freq[nums[i]]++;
    }

    for (const auto &pair : freq)
    {
        cout << pair.first << " " << pair.second << endl;
    }
}

int main()
{
    vector<int> nums = {2, 7, 11, 15, 2, 15, 15};
    int target = 9;

    frequency(nums);

    return 0;
}