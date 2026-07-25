#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
// Vector of Pairs: A vector where each element is a pair.

void printVector(const vector<pair<int, int>> &vec);
void sortVectorBySecond(vector<pair<int, int>> &vec);
bool comp(const pair<int, int> &a, const pair<int, int> &b); // comp - comparison

int main()
{
    vector<pair<int, string>> v;

    v.push_back({1, "Dev"});
    v.emplace_back(3, "Imdevx"); // emplace_back is a better alternative of push_back
    v.emplace_back(4, "Spongebob");
    v.push_back({2, "Admin"});
    
    // ==========================================
    // 1. Sorting vector of pairs
    // ==========================================
    vector<pair<int, int>> v2;

    v2.emplace_back(1, 500);
    v2.emplace_back(3, 300);
    v2.emplace_back(4, 600);
    v2.emplace_back(2, 400);

    sort(v2.begin(), v2.end()); // Default sorting: on the basis of 1st elem (if 1st elem is equal then 2nd elem)
    printVector(v2);
    cout << endl;

    sortVectorBySecond(v2); // Sort vector of pairs by second value.
    printVector(v2);

    return 0;
}

void printVector(const vector<pair<int, int>> &vec)
{
    for (const auto &elem : vec)
    {
        cout << elem.first << " " << elem.second << endl;
    }
}

void sortVectorBySecond(vector<pair<int, int>> &vec)
{
    sort(vec.begin(), vec.end(), comp);
}

bool comp(const pair<int, int> &a, const pair<int, int> &b) 
{
    return a.second < b.second;
}
