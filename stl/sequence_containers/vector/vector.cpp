#include <iostream>
#include <vector>
using namespace std;

/*
Vector: is a dynamic array
Initially
size of vector = 0 (number of elem currently stored)
capacity of vector = 0 (number of elements vector can hold before it needs to allocate more memory)
It expands automatically when needed

Whenever size == capacity
and we try to add another element, the vector triggers that doubling process (capacity x 2) to clear out room for future growth.
*/

// Creating vector
int main()
{
    // Empty vector
    vector<int> v1;

    // Fixed size vector
    vector<int> v2(5); // Output: 0 0 0 0 0

    // Fixed size vector with value
    vector<int> v3(5, 10); // Output: 10 10 10 10 10

    // Initialize using list
    vector<int> v4 = {10, 20, 30, 40, 50};

    // copy vector
    vector<int> a = {1, 2, 3};
    vector<int> b = a;

    // Accessing elems
    vector<int> v5 = {1, 2, 3, 4, 5};
    cout << v5[1] << endl;
    cout << v5.at(1) << endl;
    
    // Mutability
    vector<int> v6 = {1, 2, 3, 4, 5};
    v5[4] = 50;
    cout << v5.at(4);

    // Print vector using loops

    return 0;
}

// int main()
// {
//     vector<int> nums;

//     nums.push_back(1);
//     nums.push_back(2);
//     nums.push_back(3);

//     cout << "Vector elements are: ";

//     for (int i = 0; i < nums.size(); i++)
//     {
//         cout << nums[i] << " ";
//     }

//     cout << endl;

//     vector<int> v;

//     cout << "Size = " << v.size() << endl;
//     cout << "Capacity = " << v.capacity() << endl;

//     v.push_back(10);

//     cout << "Size = " << v.size() << endl;
//     cout << "Capacity = " << v.capacity() << endl;

//     v.push_back(20);

//     cout << "Size = " << v.size() << endl;
//     cout << "Capacity = " << v.capacity() << endl;

//     v.push_back(30);

//     cout << "Size = " << v.size() << endl;
//     cout << "Capacity = " << v.capacity() << endl;

//     return 0;
// }
