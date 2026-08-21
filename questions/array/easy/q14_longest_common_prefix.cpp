#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

string longestCommonPrefix(vector<string> &strs)
{
    // if (strs.empty())
    //     return "";

    // string longestPrefix = "";

    // int index = 0;
    // bool samePrefix = true;

    // while (samePrefix)
    // {
    //     if (index >= strs[0].length())
    //         break;

    //     for (int i = 1; i < strs.size(); i++)
    //     {
    //         if (index >= strs[i].length() || strs[i][index] != strs[0][index])
    //         {
    //             samePrefix = false;
    //             break;
    //         }
    //     }

    //     if (samePrefix)
    //     {
    //         longestPrefix += strs[0][index];
    //         index++;
    //     }
    // }
    // return longestPrefix;

    if (strs.empty())
        return "";

    // sort the string lexicographically
    sort(strs.begin(), strs.end()); 

    // get the first and last sring of strs
    string first = strs.front();
    string last = strs.back();
    string longestPrefix = "";

    for (int i = 0; i < first.size(); i++)
    {
        if (first[i] == last[i])
        {
            longestPrefix += first[i];
        }
        else
        {
            break; // break the loop at first mismatch
        }
    }

    return longestPrefix;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    auto result = longestCommonPrefix(strs);
    cout << result;
    return 0;
}

/*
The Core Sorting Rules
First Letter First
Left-to-Right Scan: If the first letters are identical, it compares the second letters, then the third, and so on.
Short Words Win: pan comes before pancake
Capital Letters First
*/