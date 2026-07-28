#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void printDeque(const deque<int> &dq);

int main()
{
    deque<int> dq = {1, 2, 3, 4, 5};

    // insert: dq.insert(iterator, value)
    dq.insert(dq.begin(), 0);
    printDeque(dq);
    cout << endl;

    // insert multiple values: dq.insert(iterator, n, value) n is how many times the value repeats
    auto it = dq.begin() + 3;
    dq.insert(it, 2, 3);
    printDeque(dq);
    cout << endl;

    // erase: dq.erase(iterator)
    dq.erase(dq.begin());
    printDeque(dq);
    cout << endl;

    // erase a range: dq.erase(iterator, iterator)
    dq.erase(dq.end() - 2, dq.end()); // its a half open interval [first, last)
    printDeque(dq);
    cout << endl;

    // assign
    deque<int> a;
    a.assign(5, 100);
    printDeque(a);
    cout << endl;

    // copy from another container
    deque<int> b = a;
    // or
    b.assign(a.begin(), a.end());
    printDeque(b);
    cout << endl;

    // resize
    deque<int> dq2 = {1, 2, 3};
    dq2.resize(6);     // 1, 2, 3, 0, 0, 0
    dq2.resize(6, 50); // 1, 2, 3, 50, 50, 50

    // decrease size
    dq2.resize(2); // 1, 2

    // swap
    deque <int> x= {1, 2, 3};
    deque <int> y= {4, 5, 6, 7, 8};
    x.swap(y);
    printDeque(x);
    cout << endl;
    printDeque(y);
    cout << endl;

    return 0;
}

void printDeque(const deque<int> &dq)
{
    for (auto elem : dq)
    {
        cout << elem << " ";
    }
}