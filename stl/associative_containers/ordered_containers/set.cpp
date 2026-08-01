#include <iostream>
#include <set>
using namespace std;

// A set is an STL container that stores unique elements in sorted (ascending) order
// we can't perform indexing in set

int main()
{
    set<int> s = {5, 2, 6, 5, 1, 1, 3, 4, 3};
    for (int num : s)
    {
        cout << num << " ";
    }
    cout << endl;

    set<int> s2;

    // insert: s2.insert(value), we can also use emplace()
    s2.insert(10);
    s2.insert(30);
    s2.insert(20);
    s2.insert(50);
    s2.insert(40);

    // find: s2.find(element)
    auto it = s2.find(40); // return an iterator pointing to element
    // if no element found returns it = s2.end();

    // erase: s2.erase(element)
    s2.erase(50);

    // erase using iterator
    s2.erase(it);

    // count: returns 1 if elem exist, 0 if not
    cout << (s2.count(50) ? "elem exist" : "elem does not exist") << endl;
    cout << (s2.count(10) ? "elem exist" : "elem does not exist") << endl;

    // size: returns no. of elem in set
    cout << "size of set: " << s2.size();

    // clear: removes all elem
    // s2.clear();

    // printing

    for (auto it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}