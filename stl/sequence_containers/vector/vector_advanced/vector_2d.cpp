#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void printVector(const vector<vector<int>> &vec);
int main()
{
    vector<vector<int>> matrix =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

    cout << "Number of rows: " << matrix.size() << endl; // number of rows
    cout << "Number of columns: " << matrix[0].size();   // number of columns
    cout << endl;

    printVector(matrix);
    cout << endl;

    // ==========================================
    // 1. Dynamically creating 2d vector
    // ==========================================
    int rows = 3, cols = 4;
    vector<vector<int>> mat(rows, vector<int>(cols)); // initially all values set to 0
    printVector(mat);
    cout << endl;

    vector<vector<int>> mat2(rows, vector<int>(cols, 5)); // initially all values set to 5
    printVector(mat2);
    cout << endl;

    // =================================================
    // 2. Jagged vectors: rows may have different sizes.
    // =================================================

    vector<vector<int>> jagged =
        {
            {1, 2},
            {3, 4, 5},
            {6}};
    printVector(jagged);

    return 0;
}

void printVector(const vector<vector<int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
