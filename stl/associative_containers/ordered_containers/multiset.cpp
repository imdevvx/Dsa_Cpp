#include <iostream>
#include <set>
using namespace std;

// multiset is exactly like a set except it allows duplicate

int main()
{
    multiset<int> ms = {10, 10, 10, 20, 30, 40, 50, 50, 50, 50}; // duplicates are preserved
    for (int num : ms)
    {
        cout << num << " ";
    }
    cout << endl;

    auto it = ms.find(50);
    ms.erase(it); // removes only one occurence

    // erase: ms.erase(elem)
    ms.erase(50); // all 50 will be removed

    // count: ms.count(elem)
    cout << ms.count(10);

    return 0;
}