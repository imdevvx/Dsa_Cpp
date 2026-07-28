#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// deque: (Double Ended Queue) is an STL container that allows:

// Fast insertion at the front
// Fast insertion at the back
// Fast deletion at the front
// Fast deletion at the back

// Note: unlike vector, deque does not provide a capacity() member function
// Also since deque provides random-access iterators, almost every algorithm that works with vectors also works with deques.

/*
| Feature           | Vector         | Deque          |
| ----------------- | -------------- | -------------- |
| Random Access     | O(1)           | O(1)           |
| push_back()       | O(1) amortized | O(1) amortized |
| push_front()      | O(n)           | O(1) amortized |
| pop_back()        | O(1)           | O(1)           |
| pop_front()       | O(n)           | O(1) amortized |
| Contiguous Memory | ✅ Yes        | ❌ No          |
| Cache Locality    | Better         | Slightly Worse |

*/

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6);         // Time complexity: O(1)
    v.insert(v.begin(), 0); // Time complexity: O(n) => becuase to insert we must shift the elem to right

    deque<int> dq = {1, 2, 3, 4, 5};

    // push back and push front
    dq.push_back(6);
    dq.push_front(0);

    // accessing elem of dq
    cout << "element at index 0: " << dq[0] << endl;    // 0
    cout << "element at index 1: " << dq.at(1) << endl; // 0

    // front and back
    cout << "element at front: " << dq.front() << endl; // 0
    cout << "element at back: " << dq.back() << endl;   // 6

    // pop back and pop front
    dq.pop_back();  // removes last elem
    dq.pop_front(); // removes first elem
    cout << "\n---FIRST AND LAST ELEMENT REMOVED---\n";

    // size empty clear
    cout <<"size of deque: "<< dq.size() << endl; // returns no. of element
    cout << (dq.empty()? "dq is empty" : "dq is not empty"); // dq.empty() returns bool (true or false)
    dq.clear(); // removes all element => size becomes 0

    return 0;
}