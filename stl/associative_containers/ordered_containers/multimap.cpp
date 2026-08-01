#include <iostream>
#include <map>
using namespace std;

// multimap is just like a map, except it allows duplicate keys.

int main()
{
    multimap<int, string> mm;
    mm.insert({1, "Rahul"});
    mm.insert({1, "Aman"});
    mm.insert({1, "Priya"});
    // Note a multimap does not supports mm[key] = value

    for (const auto &pair : mm)
    {
        cout << pair.first << " " << pair.second << endl;
    }
    /* Finding duplicate keys
    auto range = mm.equal_range(1);
    for (auto it = range.first; it != range.second; it++)
    {
        cout << it->second << endl;
    }
    */
    return 0;
}