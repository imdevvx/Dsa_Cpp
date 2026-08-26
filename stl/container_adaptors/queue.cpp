#include <iostream>
#include <queue>
using namespace std;

// queue: is a linear data structure where the element that enters first is removed first.
// FIFO = First In, First Out
// means the first element insterted is the first element removed.

/*
Think about people standing in a line at a ticket counter.

Front                Back
  ↓                    ↓
[10] → [20] → [30] → [40]

If we add 50:
[10] → [20] → [30] → [40] → [50]

If we remove one:
[20] → [30] → [40] → [50]

10 leaves first because it entered first.
*/

/*
push()   → add element to the back of the queue
pop()    → remove first element
front()  → see first element
back()   → see last element
empty()  → check whether empty
size()   → returns the number of element
*/


int main()
{
    queue<int> q;

    q.push(10); // first
    q.push(20); // second
    q.push(30); // third

    cout << q.front() << endl; // 10

    q.pop(); // removes 10

    cout << q.front() << endl; // 20
    cout << q.back() << endl;

    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}