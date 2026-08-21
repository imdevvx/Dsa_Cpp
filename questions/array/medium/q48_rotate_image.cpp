#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, 
// which means you have to modify the input 2D matrix directly. 
// DO NOT allocate another 2D matrix and do the rotation.

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
