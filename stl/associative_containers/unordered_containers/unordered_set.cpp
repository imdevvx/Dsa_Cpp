#include <iostream>
#include <unordered_set>
using namespace std;

// unordered set: stores unique elements without maintaining any order.
// implemented using a hash table

int main()
{
    unordered_set <int> us = {10, 20, 30, 40, 50};
    for (int num : us)
    {
        cout << num << " ";
    }
    
    
}