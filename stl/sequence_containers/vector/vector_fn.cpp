#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ==========================================
    // 1. Push and Pop Back Operations
    // ==========================================
    vector<int> v1;
    v1.push_back(1); // vector.push_back(value): adds an element at the end of the vector
    v1.push_back(2);
    v1.push_back(3);

    cout << "---Push and Pop back---";

    cout << "\nVector after push_back: ";
    for (size_t i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    
    v1.pop_back(); // vector.pop_back(): removes the last element
    cout << "\nVector after pop_back: ";
    for (size_t i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    
    // ==========================================
    // 2. Element Access (First and Last)
    // ==========================================
    cout << "\n\n---First and Last element---";
    cout << "\nFirst element of vector: " << v1.front(); // v1.front(): returns the first element
    cout << "\nLast element of vector: " << v1.back();   // v1.back(): returns the last element
    
    // ==========================================
    // 3. Empty and Clear Check
    // ==========================================
    cout << "\n\n---empty and clear---\n";
    cout << (v1.empty() ? "Vector is empty" : "Vector is not empty"); // v1.empty(): checks whether the vector is empty

    vector<int> v2 = {1, 2, 3};
    cout << "\nCapacity of v2: " << v2.capacity();
    
    v2.clear(); // v2.clear(): Removes all elements. (does not reduce capacity)
    cout << "\nCapacity of v2 after clear: " << v2.capacity();

    // ==========================================
    // 4. Resize Variations
    // ==========================================
    cout << "\n\n---resize---\n";
    vector<int> v3 = {1, 2, 3};

    // Case 1: Increase size (fills new slots with 0)
    v3.resize(6); // v3.resize(): changes the size of the vector
    for (size_t i = 0; i < v3.size(); i++) {
        cout << v3[i] << " "; 
    }
    cout << endl;

    // Case 2: Custom value (will not change existing 6 elements)
    v3.resize(6, 100);
    for (size_t i = 0; i < v3.size(); i++) {
        cout << v3[i] << " "; 
    }
    cout << endl;
    
    // Case 3: Decrease size (remaining items are removed)
    v3.resize(2);
    for (size_t i = 0; i < v3.size(); i++) {
        cout << v3[i] << " "; 
    }
    cout << endl;
    
    return 0;
}
