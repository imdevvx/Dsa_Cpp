#include <iostream>
#include <vector>
using namespace std;

/*
• Prefix Array (pref): Accumulates data from left to right 
  (from the start of the array to the current index i).
• Suffix Array (suff): Accumulates data from right to left 
  (from the end of the array down to the current index i)
=> The ith index is included

Note in this question we are excluding the ith index because ATQ we don't want that
*/



vector<int> prefixProduct(vector<int> &nums)
{
    vector<int> prefix(nums.size());
    prefix[0] = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        prefix[i] = prefix[i - 1] * nums[i - 1];
        
    }
    
    return prefix;
}

vector<int> suffixProduct(vector<int> &nums)
{
    vector<int> suffix(nums.size());
    suffix[nums.size() - 1] = 1 ;
    
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }
    
    return suffix;
}

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> answer(nums.size());

    vector <int> prefix = prefixProduct(nums);
    vector <int> suffix = suffixProduct(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        answer[i] = prefix[i] * suffix[i];
    }
    
    
    return answer;
}


int main()
{
    vector <int> nums = {-1, 1, 0, -3, 3};

    vector <int> prefix = prefixProduct(nums);
    for(int &x: prefix){
        cout << x << " ";
    }
    
    cout << endl;
    
    vector <int> suffix = suffixProduct(nums);
    for(int &x: suffix){
        cout << x << " ";
    }
    
    cout << endl;
    
    vector <int> result =  productExceptSelf(nums);
    for(int &x: result){
        cout << x << " ";
    }


    return 0;
}




/*
Most Optimal Solution - TC O(n), O(1) Space

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);

        // prefix
        for (int i = 1; i < nums.size(); i++) {
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        
        // calculate suffix and multiply by prefix
        int suffix = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            suffix *= nums[i + 1];
            answer[i] *= suffix;
        }

        return answer;
    }
};
*/