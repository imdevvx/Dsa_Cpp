#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// unordered map is implemented using a hash table

int main()
{
    vector<int> arr = {1, 2, 1, 3, 2, 1};

    unordered_map<int, int> freq;

    for (int x : arr)
    {
        freq[x]++;
    }

    for (const auto &pair : freq)
    {
        cout << pair.first << " " << pair.second << endl;
    }
    return 0;
}
