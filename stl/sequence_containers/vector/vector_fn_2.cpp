#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // ====================================================
    // 1. Reserve: one of the most important stl functions.
    // ====================================================

    // Every time the vector becomes full, it allocates new memory. That is expensive.
    // If you already know you need around n elements, reserve memory first.

    vector<int> v;
    v.reserve(100); // memory is allocated once
    // reserve changes capacity but it does not changes size.

    cout << v.size() << endl;     // 0
    cout << v.capacity() << endl; // 100

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // ====================================================
    // 2. Shrink to fit
    // ====================================================
    v.shrink_to_fit();
    // we have capacity = 100 but have only 5 elem {Memory is wasted thus use shrink_to_fit()}
    cout << v.capacity() << endl; // 5

    // ====================================================
    // 3. Swap
    // ====================================================
    vector<int> a = {1, 2, 3};
    vector<int> b = {10, 20};

    a.swap(b);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }

    // ====================================================
    // 4. Assign: Replace all elements
    // ====================================================
    cout << endl;
    b.assign(a.begin(), a.end());
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }
    
    // ====================================================
    // 5. Insert: Insert anywhere
    // ====================================================
    cout << endl;
    b.insert(b.begin() + 2, 30);
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }

    // ====================================================
    // 6. Erase: erase elements
    // ====================================================
    cout << endl;
    // b.erase(index) // delete a specific value
    // b.erase(index begin, index end) // delete a range


    return 0;
}
