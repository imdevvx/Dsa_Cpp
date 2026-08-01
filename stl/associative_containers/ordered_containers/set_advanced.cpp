#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s = {10, 20, 30, 40, 40, 50, 60};

    // lower_bound: returns an iterator pointing to the first element that is greater than or equal to the given value.
    auto it = s.lower_bound(20);
    cout << *it << endl; // 20
    it = s.lower_bound(25);
    cout << *it << endl; // 30

    // upper_bound: returns the first element strictly greater than the given value.
    it = s.upper_bound(20);
    cout << *it << endl; // 30
    it = s.upper_bound(25);
    cout << *it << endl; // 30

    // equal_range: returns both (a pair containing two iterators) lower and upper bounds together.
    auto p = s.equal_range(30);
    cout << *p.first << " " << *p.second;

    // swap
    set<int> a = {1, 2, 3};
    set<int> b = {10, 20};
    a.swap(b);

    return 0;
}