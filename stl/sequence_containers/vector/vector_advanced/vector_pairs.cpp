#include <iostream>
using namespace std;
#include <vector>
#include <queue>
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

    cout << "\n---PRIORITY QUEUE---\n";
    priority_queue<pair<int, int>> pq;
    pq.push({5, 100});
    pq.push({3, 200});
    pq.push({7, 300});

    cout << pq.top().first << " " << pq.top().second; // default comparison is lexicographical. largest first comes first

    cout << "\n---PAIR IN GRAPHS---\n";
    vector<pair<int, int>> graph[5];
    graph[0].push_back({1, 5}); // 0 connects to City 1, weight 5
    graph[0].push_back({2, 3}); // 0 connects to City 2, weight 3

    for (auto edge : graph[0])
    {
        int neighbor = edge.first; // This will be 1, then 2
        int weight = edge.second;  // This will be 5, then 3
        cout << "0 -> " << neighbor << " (weight " << weight << ")\n";
    }

    // Pair in Dijkstra -:
    // a greedy graph algorithm that finds the shortest path from a single source node to all other nodes in a weighted graph with non-negative edge weights.
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;

    return 0;
}

void printVector(const vector<pair<int, int>> &vec)
{
    for (const auto &elem : vec)
    {
        cout << elem.first << " " << elem.second << endl;
    }

    // Modern C++ allows unpacking pairs directly. (not working in our compiler)
    // for (const auto &[num1, num2]: vec)
    // {
    //     cout << num1 << " " << num2 << endl;
    // }
}

void sortVectorBySecond(vector<pair<int, int>> &vec)
{
    sort(vec.begin(), vec.end(), comp);
}

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
