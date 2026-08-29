#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Given an integer x, return true if x is a palindrome, and false otherwise.

bool isPalindrome(int x)
{
    string num = to_string(x);
    int left = 0;
    int right = num.length() - 1;

    // A negative number can't be a plaindrome => -121 != 121-
    if (num[left] == '-')
    {
        return false;
    }

    while (left <= right)
    {
        if (num[left] != num[right])
        {
            return false;
        }
        left++;
        right--;
    }

    return true;
    
}

int main()
{
    int x = 101;
    bool result = isPalindrome(x);

    cout << result;

    return 0;
}