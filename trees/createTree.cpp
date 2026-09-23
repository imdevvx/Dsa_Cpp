#include <iostream>
#include <vector>
using namespace std;

/* CREATE A BINARY TREE FIXED POSITION ARRAY

For a complete/level-order binary tree,
the children of index i are:

left child  = 2*i + 1
right child = 2*i + 2
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

    TreeNode *createTreeHelper(const vector<int> &arr, int i)
    {
        if (i >= arr.size() || arr[i]) 
            return nullptr;

        TreeNode *node = new TreeNode(arr[i]);
        node->left = createTreeHelper(arr, (2 * i) + 1);
        node->right = createTreeHelper(arr, (2 * i) + 2);
        return node;
    }

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

public:
    Tree()
    {
        root = nullptr;
    }

    void *createTree(vector<int> &arr)
    {
        root = createTreeHelper(arr, 0);
    }

    void inorder()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    vector<int> nums = {5, 3, 7, 2, 8, 1, 9};
    Tree t;

    t.createTree(nums);
    t.inorder();

    return 0;
}




/*
Using loops

#include <vector>
#include <queue>

class Solution {
private:
    // A helper struct to store the state of each step
    struct NodeInfo {
        TreeNode* parent; // The parent node we need to attach a child to
        bool isLeft;      // True if this child belongs on the left, false for right
        int start;        // Left boundary of the subarray
        int end;          // Right boundary of the subarray
    };

public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.empty()) return nullptr;

        // 1. Process the absolute root of the tree first
        int mid = 0 + (nums.size() - 1 - 0) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        // 2. Initialize a queue to hold our "todo" list
        std::queue<NodeInfo> q;

        // Push the left and right sub-problems of the root node
        if (0 <= mid - 1) {
            q.push({root, true, 0, mid - 1});
        }
        if (mid + 1 <= nums.size() - 1) {
            q.push({root, false, mid + 1, (int)nums.size() - 1});
        }

        // 3. The Loop: Keep processing as long as there are segments left
        while (!q.empty()) {
            NodeInfo curr = q.front();
            q.pop();

            // Find the middle element of the current segment
            int current_mid = curr.start + (curr.end - curr.start) / 2;
            TreeNode* childNode = new TreeNode(nums[current_mid]);

            // Connect the newly created node to its parent
            if (curr.isLeft) {
                curr.parent->left = childNode;
            } else {
                curr.parent->right = childNode;
            }

            // If there's a valid left sub-range, add it to the queue
            if (curr.start <= current_mid - 1) {
                q.push({childNode, true, curr.start, current_mid - 1});
            }
            // If there's a valid right sub-range, add it to the queue
            if (current_mid + 1 <= curr.end) {
                q.push({childNode, false, current_mid + 1, curr.end});
            }
        }

        return root;
    }
};

*/