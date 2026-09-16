#include <vector>
#include <queue>
using namespace std;
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

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        if (root == nullptr)
            return {};

        vector<vector<int>> result;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {

            vector<int> currentNodes;
            int currSize = q.size();

            for (int i = 0; i < currSize; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                currentNodes.push_back(curr->val);

                if (curr->left != nullptr)
                    q.push(curr->left);
                if (curr->right != nullptr)
                    q.push(curr->right);
            }

            result.push_back(currentNodes);
        }

        return result;
    }
};