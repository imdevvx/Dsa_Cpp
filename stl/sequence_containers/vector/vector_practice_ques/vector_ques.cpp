#include <iostream>
using namespace std;
#include <vector>

int main()
{
    // Create an empty vector of integers
    vector<int> my_vector;

    // 1. Print size and capacity after every push_back()
    cout << "--- Pushing elements and tracking memory ---\n";

    int elements[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i)
    {
        my_vector.push_back(elements[i]);
        cout << "Added " << elements[i]
             << " -> Size: " << my_vector.size()
             << ", Capacity: " << my_vector.capacity() << "\n";
    }

    // 2. Print the first and last element
    cout << "\n--- First and Last Elements ---\n";
    cout << "First element: " << my_vector.front() << "\n";
    cout << "Last element: " << my_vector.back() << "\n";

    // 3. Change the third element (index 2) to 100
    my_vector[2] = 100;

    // 4. Print the vector using an Index-based for loop
    cout << "\n--- Printing with Index-based for loop ---\n";
    for (size_t i = 0; i < my_vector.size(); ++i)
    {
        cout << my_vector[i] << " ";
    }
    cout << "\n";

    // 5. Print the vector using a Range-based for loop
    cout << "\n--- Printing with Range-based for loop ---\n";
    for (int num : my_vector)
    {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
