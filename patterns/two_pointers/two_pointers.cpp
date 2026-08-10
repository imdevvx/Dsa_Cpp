#include <iostream>
#include <vector>
using namespace std;

/*
two-pointer approach is an efficient algorithmic technique in C++ 
used primarily to search pairs, triplets, or subarrays in a linear data structure like arrays or vectors. 
It optimizes brute-force solutions by using two indices (pointers) that traverse the data structure simultaneously, 
reducing the time complexity from O(N²) to O(N)

Use the two-pointer technique when:

The array is sorted.
You need to find a pair that satisfies a condition.
You need to remove duplicates.
You need to reverse an array or string.
You need to solve sliding window-like problems (a variation of two pointers).
*/

bool isPalindrome(const string &str)
{
    int left = 0;
    int right = str.length() - 1;

    while (left < right)
    {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main()
{
    string str = "madam";
    auto result = isPalindrome(str);
    cout << (result ? "its a palindrome" : "not a palindrome");
    return 0;
}