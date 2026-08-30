#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type
*/

bool isValid(string s)
{
    if (s.length() % 2 != 0)
        return false;

    std::stack<char> st;

    for (char c : s)
    {
        // If it's an opening bracket, push it onto the stack
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        // If it's a closing bracket, validate and pop
        else
        {
            // Stack cannot be empty when a closing bracket arrives
            if (st.empty())
                return false;

            char top = st.top();
            // Check if the current closing bracket matches the top opening bracket
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '['))
            {
                st.pop();
            }
            else
            {
                // Mismatched bracket type
                return false;
            }
        }
    }

    // If stack is empty, all brackets were matched correctly
    return st.empty();
}

int main()
{
    string s1 = "({[]})";
    string s2 = "()[]{}";
    string s3 = "()[]{)";
    bool result1 = isValid(s1);
    bool result2 = isValid(s2);
    bool result3 = isValid(s3);
    cout << result1 << endl;
    cout << result2 << endl;
    cout << result3 << endl;
    return 0;
}