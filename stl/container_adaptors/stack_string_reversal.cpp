#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string greet = "Hello";
    stack<char> st;

    for (int i = 0; i < greet.length(); i++)
    {
        st.push(greet[i]);
    }

    stack<char> temp = st;

    while (!temp.empty())
    {
        cout << temp.top();
        temp.pop();
    }

    return 0;
}