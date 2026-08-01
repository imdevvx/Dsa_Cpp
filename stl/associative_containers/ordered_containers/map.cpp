#include <iostream>
#include <map>
using namespace std;

// map is an STL container that stores key-value pairs.
/*
Properties of map -:
- keys are unique
- keys are automatically sorted
- values can repeat
- fast searching (Time complexity O(log n))
*/

int main()
{
    map<string, int> mp;

    // insertion
    mp.insert({"admin", 1});
    mp["dev"] = 2;

    // update value
    mp["admin"] = 0;
    mp["dev"] = 1;
    mp["imdevx"] = 2;

    for (const auto &pair : mp)
    {
        cout << pair.first << " " << pair.second << endl;
    }

    // access value
    cout << mp.at("dev") << endl;

    // find
    auto it = mp.find("dev"); // returns an iterator pointing to the pair, if not found returns mp.end();
    cout << it->first << " " << it->second << endl;

    // erase
    mp.erase("dev"); // removes specific key value pair

    // count: checks if a key exist, since key can't be same
    cout << (mp.count("admin") ? "key exist" : "key doesn't exist") << endl;
    cout << (mp.count("dev") ? "key exist" : "key doesn't exist") << endl;

    // Iterating Through Map
    /* using loop */
    for (auto x : mp)
    {
        cout << x.first << " " << x.second << endl;
    }
    /* using iterator because the iterator points to a pair<const key, value>*/
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    // empty: returns true or false on the basis of empty or not
    // clear: clears mp

    return 0;
}