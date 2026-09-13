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

    // Preorder (NLR): Root → Left → Right
    void preorder(TreeNode<T> *root)
    {
        if (root == nullptr)
            return;

        cout << root->val << " ";

        preorder(root->left);
        preorder(root->right);
    }

    // Inorder (LNR): Left → Root → Right
    void inorder(TreeNode<T> *root)
    {

        if (root == nullptr)
            return;

        inorder(root->left);

        cout << root->val << " ";

        inorder(root->right);
    }

    // Postorder (LRN): Left → Right → Root
    void postorder(TreeNode<T> *root)
    {
        if (root == nullptr)
            return;

        postorder(root->left);
        postorder(root->right);

        cout << root->val << " ";
    }

    // Level Order: Level by Level
    void levelorder(TreeNode<T> *root)
    {
        if (root == nullptr)
            return;
        queue<TreeNode<T> *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode<T> *curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }

    void preorder()
    {
        preorder(root);
    }
    void inorder()
    {
        inorder(root);
    }
    void postorder()
    {
        postorder(root);
    }

    void levelorder()
    {
        levelorder(root);
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

    cout << "Preorder: ";
    tree.preorder();
    cout << endl;

    cout << "Inorder: ";
    tree.inorder();
    cout << endl;

    cout << "Postorder: ";
    tree.postorder();
    cout << endl;

    cout << "Level order: ";
    tree.levelorder();
    cout << endl;

    return 0;
}