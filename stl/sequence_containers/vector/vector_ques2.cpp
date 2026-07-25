#include <iostream>
using namespace std;
#include <vector>

int main()
{

    vector<int> v = {2, 1, 5, 3, 4};

    int largest = v[0];
    int smallest = v[0];
    int sum = 0;
    int evens = 0;
    int odds = 0;
    
    cout << "\nVector: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    int start = 0;
    int end = v.size() - 1; // 4

    while(start < end){
        int temp = v[start];
        v[start] = v[end];
        v[end] = temp;

        start++;
        end--;
    }
    cout << "\nReversed vector: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > largest)
        {
            largest = v[i];
        }
        if (v[i] < smallest)
        {
            smallest = v[i];
        }

        sum += v[i];

        if (v[i] % 2 == 0)
        {
            evens++;
        }
        else
        {
            odds++;
        }
    }

    cout << "\nLargest: " << largest << endl;
    cout << "Smallest: " << smallest << endl;
    cout << "Sum: " << sum << endl;
    cout << "Evens: " << evens << endl;
    cout << "Odds: " << odds << endl;

    return 0;
}
