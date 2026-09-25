#include <iostream>
using namespace std;

/*
Given a string s, calculate its reverse degree.

The reverse degree is calculated as follows:

For each character, 
multiply its position in the reversed alphabet ('a' = 26, 'b' = 25, ..., 'z' = 1) 
with its position in the string (1-indexed).

Sum these products for all characters in the string.

Return the reverse degree of s.
*/

int reverseDegree(string s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char x = s[i];
        int reversed_lexi_val = 'z' - x + 1;
        sum += (i + 1) * reversed_lexi_val;
    }
    return sum;
}

int main()
{
    string s = "";
    int result = reverseDegree(s);
    cout << result;
}