#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
Given an m x n integer matrix matrix,
if an element is 0, set its entire row and column to 0's.
You must do it in place.
*/

void setZeroes(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix.front().size();

    set<int> zero_rows;
    set<int> zero_cols;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                zero_rows.insert(i);
                zero_cols.insert(j);
            }
        }
    }

    for (const int &row : zero_rows)
    {
        fill(matrix[row].begin(), matrix[row].end(), 0);
    }

    for (const int &col : zero_cols)
    {
        for (int i = 0; i < row; i++)
        {
            matrix[i][col] = 0;
        }
    }
}

void displayMatrix(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix.front().size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}};

    cout << "Original Matrix:" << endl;
    displayMatrix(matrix);

    setZeroes(matrix);

    cout << "\nModified Matrix:" << endl;
    displayMatrix(matrix);

    return 0;
}