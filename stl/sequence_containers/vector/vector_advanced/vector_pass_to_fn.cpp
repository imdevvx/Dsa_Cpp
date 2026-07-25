#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(const vector<int> &vec);
void sortVector(vector<int> &vec);
void modifyLocalVectorCopy(vector<int> vec);
vector<int> generateNum(int count);

int main()
{
    vector<int> v = {5, 3, 1, 4, 2};
    printVector(v);
    cout << endl;

    sortVector(v);
    printVector(v);
    cout << endl;
    
    modifyLocalVectorCopy(v);
    printVector(v);
    cout << endl;

    vector<int> numVector = generateNum(5);
    printVector(numVector);

    return 0;
}

// Accepts the vector efficiently by const pass by ref
void printVector(const vector<int> &vec)
{
    for (auto &elem : vec)
    {
        cout << elem << " ";
    }
}

// Accepts the vector by reference to modify it in place
void sortVector(vector<int> &vec)
{
    sort(vec.begin(), vec.end());
}

// Accepts the vector by value Modifying 'vec' here will NOT change the vector in main()
void modifyLocalVectorCopy(vector<int> vec)
{
    vec.push_back(6); // Only affects this local copy
    cout << "Local vector copy: ";
    printVector(vec);
}

// Return a vector
vector<int> generateNum(int count)
{
    vector<int> result;
    for (int i = 1; i <= count; i++)
    {
        result.push_back(i);
    }
    return result;
}