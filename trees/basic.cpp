template <typename T>

class TreeNode
{
    T val;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(T data = 0)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

/*
For example -:

Node* root = new Node(1);
creates -:
   1
  / \
null null

Then we can connect nodes -:
root->left = new Node(2);
root->right = new Node(3);
Now -:
  1
 / \
2   3
*/