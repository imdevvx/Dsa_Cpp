#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> mp;
    mp[10] = "A";
    mp[20] = "B";
    mp[30] = "C";

    // lower_bound: returns an iterator pointing to the first key that is greater than or equal to the given key.
    auto it = mp.lower_bound(20);
    cout << it->first << " " << it->second << endl; // 20 B
    it = mp.lower_bound(25);
    cout << it->first << " " << it->second << endl; // 30 C
    // if the key doesn't exist returns mp.end()

    // upper_bound: returns the first key that is strictly greater than the given key.
    it = mp.upper_bound(20);
    cout << it->first << " " << it->second << endl; // 30 C
    it = mp.upper_bound(25);
    cout << it->first << " " << it->second << endl; // 30 C

    // equal_range: returns both bounds together
    auto p = mp.equal_range(20);
    cout << p.first->first << " " << p.first->second << endl;
    cout << p.second->first << " " << p.second->second << endl;

    // emplace: instead of insert mp.({key, val}), mp.emplace(key, val)
    // swap: swaps two map

    return 0;
}