#include <iostream>
#include <stack>
using namespace std;

// stack: is a linear data structure that follows the LIFO principle.
// LIFO = Last In, First Out
// means the last element insterted is the first element removed.
// stack doesn't stores element itself instead, it user another conatiner (deque) internally

/*
Imagine a stack of plates.
  Top
+------+
|  40  | ← Last plate added
+------+
|  30  |
+------+
|  20  |
+------+
|  10  |
+------+
We can't remove the middle plate directly. 
We must remove from the top.
*/

int main()
{
    stack<int> st;

    // push() adds an element to the top
    st.push(10);
    st.push(20);
    st.push(30);
    return 0;
}