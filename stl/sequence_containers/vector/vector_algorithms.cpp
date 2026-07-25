#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Iterator: is an object that points to an element inside a container.
// so indtead of using indexes to target elem we'll use iterator, because not every container supports indexing.
// Normal Iterator (end()): Decrementing (--) moves it left (back into the vector elements).
// Reverse Iterator (rend()): Incrementing (++) moves it left (further away from the vector elements).
// vector<int>::iterator it;     // declare an iterator named it specifically designed for a vector of integers.
// instead of writing this we can use the auto keyword

int main()
{
    vector<int> v = {10, 20, 30}; // initialize the vector with three elements: 10, 20, and 30

    // ==========================================
    // 1. begin and end
    // ==========================================
    cout << "---begin and end---\n";
    auto it = v.begin(); // begin(): returns an iterator pointing to the first element.
    cout << *it << endl; // dereference to access the value

    it++; // Moving iterator
    cout << *it << endl;

    it = v.end(); // end(): returns an iterator pointing past the last element
    cout << *(--it) << endl;

    cout << "\n---Printing full vector using iterator---\n";
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    // ==========================================
    // 2. rbegin and rend
    // ==========================================
    cout << endl;
    cout << "\n---rbegin and rend (r = reverse)---\n";
    vector<int> v2 = {1, 2, 3};

    auto it2 = v2.rbegin(); // returns an iterator pointing to the last element
    cout << *it2 << endl;

    it2 = v2.rend(); // returns an iterator pointing before the first element
    cout << *(--it2) << endl;

    // ==========================================
    // 3. cbegin and cend
    // ==========================================
    cout << "\n---cbegin and cend (c = constant)---\n";
    vector<int> v3 = {1, 2, 3};

    auto it3 = v3.cbegin();
    // *it3 = 100; // can't modify constant (compilation error)
    cout << *it3 << endl;

    it3 = v3.cend();
    cout << *(--it3) << endl;

    cout << "\n---using algorithms---\n";
    vector<int> v4 = {5, 3, 8, 6, 1, 9, 1};

    cout << "Original vector: ";
    for (int num : v4)
    {
        cout << num << " ";
    }
    cout << endl;

    // ==========================================
    // 4. Reverse
    // ==========================================
    reverse(v4.begin(), v4.end());
    cout << "reverse: ";
    for (int num : v4)
    {
        cout << num << " ";
    }
    cout << endl;

    // ==========================================
    // 5. Sort
    // ==========================================
    sort(v4.begin(), v4.end()); // sorts everything between those two iterators.
    cout << "sort: (ascending order): ";
    for (int num : v4)
    {
        cout << num << " ";
    }
    cout << endl;

    sort(v4.begin(), v4.end(), greater<int>()); // descending sort
    cout << "sort: (descending order): ";
    for (int num : v4)
    {
        cout << num << " ";
    }
    cout << endl;

    // ==========================================
    // 6. Find
    // ==========================================
    auto it4 = find(v4.begin(), v4.end(), 5); // if elem exist returns iterator if not then returns it == v.end()
    cout << "find: " << (it4 != v.end() ? "Found" : "Not Found") << endl;

    // ==========================================
    // 4. Max and Min element
    // ==========================================
    it4 = max_element(v4.begin(), v4.end());
    cout << "max_element: " << *it4 << endl;

    it4 = min_element(v4.begin(), v4.end());
    cout << "min_element: " << *it4 << endl;

    // ==========================================
    // 7. Count
    // ==========================================
    cout << "count: " << count(v4.begin(), v4.end(), 1) << endl; // occurence of 1

    // ==========================================
    // 8. Binary search
    // ==========================================
    // Binary search -:
    // 1st sort, 2nd check if elem exist, 3rd get the exact index of elem

    cout << "\nBinary search -:\n";
    vector<int> v5 = {5, 6, 2, 8, 9, 1, 7};
    sort(v5.begin(), v5.end());
    cout << "Sorted vector: ";
    for (int num : v5)
    {
        cout << num << " ";
    }
    cout << endl;

    int target = 5;

    bool elem_exist = binary_search(v5.begin(), v5.end(), target);
    cout << (elem_exist ? "Element exist & " : "Eelement doesn't exist");

    // ==========================================
    // 9. Lower and upper bound
    // ==========================================
    auto it5 = lower_bound(v5.begin(), v5.end(), target); // points to the first elem >= the target => OTPUT: 8
    if (it5 != v5.end() && *it5 == target)
    {
        int index = distance(v5.begin(), it5);
        cout << "Found at index: " << index << endl;
    }

    it5 = upper_bound(v5.begin(), v5.end(), target); // points to the first element that is strictly greater than the target
    cout << *it5;

    return 0;
}