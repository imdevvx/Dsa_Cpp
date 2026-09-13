struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

/*
Given the roots of two binary trees p and q, 
write a function to check if they are the same or not.

Two binary trees are considered the same 
if they are structurally identical, 
and the nodes have the same value.
*/

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q== nullptr) return true;

        if(p == nullptr || q==nullptr || p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*
      50         50
     /  \       /  \
    30   70    30   70

isSameTree(50, 50)
    return isSameTree(30, 30) && isSameTree(70, 70)

Now -:
isSameTree(30, 30)
    return isSameTree(nullptr, nullptr) && isSameTree(nullptr, nullptr)

First: isSameTree(nullptr, nullptr): return true
Second: isSameTree(nullptr, nullptr): return true
Therefore: true && true = true

Then we return to the original call => isSameTree(50, 50)
which is waiting here: 
return isSameTree(30,30) && isSameTree(70,70)

since the left side returned true, 
we now evaluate isSameTree(70, 70)
which again returns true eventually

Then we return to the original call again => isSameTree(50, 50)
return true && true = true;
*/