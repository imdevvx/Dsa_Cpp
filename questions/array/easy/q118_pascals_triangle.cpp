#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> pascalTriangle;

    for (int i = 0; i < numRows; i++)
    {
        vector<int> row(i + 1, 1); // Fill the entire row with 1s

        for (int j = 1; j < i; j++)
        {
            row[j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
        }

        pascalTriangle.push_back(row);
    }
    return pascalTriangle;
}

int main()
{
    int numRows = 5;
    auto result = generate(numRows);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
