#include <iostream>
#include <stack>
using namespace std;

// stack: is a linear data structure that follows the LIFO principle.
// LIFO = Last In, First Out
// means the last element insterted is the first element removed.
// stack doesn't stores element itself instead, it uses another conatiner (deque) internally

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

/*
push()   → add element
pop()    → remove top element
top()    → see top element
empty()  → check whether empty
*/

/*
Important points
=> Stack does not supports indexing
=> Stack does not have iterators

*/

int main()
{
  stack<int> st;

  st.push(10);
  st.push(20);
  st.push(30);

  cout << st.top() << endl;
  st.pop();
  cout << st.top() << endl;

  if (st.empty())
  {
    cout << "Stack is empty" << endl;
  }

  cout << st.size() << endl;

  // we are using temp so that our original stack does not get destroyed
  stack<int> temp = st;
  while (!temp.empty())
  {
    cout << temp.top() << " ";
    temp.pop();
  }

  return 0;
}

// (([[{}]]))