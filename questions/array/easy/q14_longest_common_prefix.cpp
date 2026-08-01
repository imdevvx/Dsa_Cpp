#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{

    if (strs.empty())
        return "";

    string longestPrefix = "";

    int index = 0;
    bool samePrefix = true;

    while (samePrefix)
    {
        if (index >= strs[0].length())
            break;

        for (int i = 1; i < strs.size(); i++)
        {
            if (index >= strs[i].length() || strs[i][index] != strs[0][index])
            {
                samePrefix = false;
                break;
            }
        }

        if (samePrefix)
        {
            longestPrefix += strs[0][index];
            index++;
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