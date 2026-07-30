#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Binary tree: a tree where each node has no more than 2 children

Binary search tree: a specialized variant of a standard binary tree
- Core properties -:
  - Left Subtree: The values of all nodes in the left subtree must be strictly less than the parent node's value.
  - Right Subtree: The values of all nodes in the right subtree must be strictly greater than the parent node's value.
  - Subtrees: Both the left and right subtrees must also recursively satisfy the rules of a binary search tree.
  - No Duplicates: Standard BSTs do not allow nodes with duplicate values to maintain clear ordering constraints.
This means the left most child is the least value and the right most child is the greatest

Height balanced tree: the heights of the left and right subtree differ by at most 1
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *sortedArrayToBST(vector<int> &nums);

int main()
{
    return 0;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int mid = nums.size() / 2;
    vector <int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        
    }
    
}
