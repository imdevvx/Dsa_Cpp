#include <iostream>
#include <vector>
using namespace std;

/* One pointer starts from the beginning and the other from the end. */
// Q. Find two numbers whose sum is target, return indices

vector<int> sum_target(vector<int> nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        int sum = nums[left] + nums[right];

        if (sum == target)
            return {left, right};
        else if (sum > target)
            right--;
        else
            left++;
    }
    return {};
}

string reverse(string &str){
    int left = 0;
    int right = str.length() - 1;

    while (left < right){
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }

    return str;
}

int main()
{
    vector<int> nums = {1, 3, 4}; // sorted array
    int target = 7;

    auto result = sum_target(nums, target);
    for (int idx : result)
    {
        cout << idx << " ";
    }

    string str = "HELLO";
    auto result2 = reverse(str);
    cout << str;
    
    return 0;
}