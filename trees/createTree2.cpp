#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* CREATE A BINARY TREE LEVEL ORDER INPUT WITH MISSING NODES

Queue
 ↓
Take a node
 ↓
Attach left child
 ↓
Attach right child
 ↓
Put children into queue
 ↓
Repeat
*/

class TreeNode
{
private:
    int val;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(int data = 0)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }

    friend class Tree;
};

class Tree
{
private:
    TreeNode *root;

public:
    Tree()
    {
        root = nullptr;
    }

    void levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            cout << curr->val << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    void createTree(vector<int> &arr)
    {
        if (arr.empty() || arr[0] == -1)
            return;

        root = new TreeNode(arr[0]);

        queue<TreeNode *> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < arr.size())
        {
            TreeNode *curr = q.front();
            q.pop();

            // Left child
            if (arr[i] != -1)
            {
                curr->left = new TreeNode(arr[i]);
                q.push(curr->left);
            }

            i++;

            // Right child
            if (i < arr.size() && arr[i] != -1)
            {
                curr->right = new TreeNode(arr[i]);
                q.push(curr->right);
            }

            i++;
        }
    }

    void levelOrder(){
        levelOrder(root);
    }
};

int main()
{
    vector<int> nums = {5, 3, -1, 2, 8, -1, 9};
    Tree t;

    t.createTree(nums);
    t.levelOrder();
    return 0;
}