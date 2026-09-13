#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class Tree;

template <typename T>
class TreeNode
{
private:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

public:
    TreeNode(int data = 0)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
    friend class Tree<T>;
};

template <typename T>
class Tree
{
private:
    TreeNode<T> *root;

    // Hepler fn for insertion
    void insert(TreeNode<T> *&node, T data)
    {
        if (node == nullptr)
        {
            node = new TreeNode<T>(data);
            return;
        }

        if (data < node->val)
            insert(node->left, data);
        else
            insert(node->right, data);
    }

public:
    Tree()
    {
        root = nullptr;
    }

    void insert(T data)
    {
        insert(root, data);
    }

    // LNR
    void inorder(TreeNode<T> *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    void inorder()
    {
        inorder(root);
    }
};

int main()
{
    Tree<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);

    tree.inorder();

    return 0;
}

/*
void inorder(TreeNode<T> *node)
{
    if (node == nullptr)
    return;
    inorder(node->left);
    cout << node->val << " ";
    inorder(node->right);
}
    
      50
     /  \
    30    70
   / \ 
 20   40 

inorder(50)
inorder(30) => inorder(50) is paused here
inorder(20) => inorder(30) is paused here
inorder(nullptr) => inorder(20) is paused here
                    inorder(nullptr) returns {as base case}, goes back to inorder(20) waiting in the call stack, 
                    next line executes

inorder(20): prints 20,
             inorder(20->right)

inorder(nullptr): returns, goes back to inorder(30) waiting in the call stack
                  next line executes

inorder(30): prints 30,
             inorder(30->right)

inorder(40): prints 40,
             inorder(40->right)

inorder(nullptr): returns, goes back to inorder(50) waiting in the call stack
                  next line executes

inorder(50): prints 50,
             inorder(50->right)

inorder(70): inorder(70->left)
inorder(nullptr): returns, goes back to inorder(70) waiting in the call stack
                  next line executes

inorder(70): prints 70, 
             inorder(70->right)
inorder(nullptr): return
*/

/*
inorder(50)
│
├── inorder(30)
│   │
│   ├── inorder(20)
│   │   │
│   │   ├── inorder(nullptr) → return
│   │   │
│   │   ├── print 20
│   │   │
│   │   └── inorder(nullptr) → return
│   │
│   ├── print 30
│   │
│   └── inorder(40)
│       │
│       ├── inorder(nullptr) → return
│       │
│       ├── print 40
│       │
│       └── inorder(nullptr) → return
│
├── print 50
│
└── inorder(70)
    │
    ├── inorder(nullptr) → return
    │
    ├── print 70
    │
    └── inorder(nullptr) → return
*/

/*
When say inorder(70) is called it will fully complete only when 
all the lines of code fully executes
means 
inorder(70->left)
cout...
inorder(70->right) {after this line fully finishes inorder(70) completes}
*/