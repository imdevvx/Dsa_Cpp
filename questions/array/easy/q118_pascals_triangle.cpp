#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
