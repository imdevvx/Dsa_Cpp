#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void transposeMatrix(vector<vector<int>> &matrix)
{
    // matrix.size() = row = col, since we are working on square matrix.

    cout << "Transpose matrix -:\n";
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i + 1; j < matrix.size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void displayMatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void reverseRow(vector<vector<int>> &matrix)
{
    cout << "Reverse row matrix of transpose -:\n";

    for (auto &row : matrix)
    {
        reverse(row.begin(), row.end());
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    transposeMatrix(matrix);
    reverseRow(matrix);
    displayMatrix(matrix);

    return 0;
}
