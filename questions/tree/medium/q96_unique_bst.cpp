#include <vector>
using namespace std;

/*
Given an integer n,
return the number of structurally unique BST's (binary search trees)
which has exactly n nodes of unique values from 1 to n.
*/

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        // How many nodes are we currently trying to put into the BST
        for (int nodes = 2; nodes <= n; nodes++)
        {
            // We're trying every possible node as the root.
            // Each root produces a different split between the left and right subtrees.
            for (int root = 1; root <= nodes; root++)
            {
                int left_nodes = root - 1;
                int right_nodes = nodes - root;

                dp[nodes] += dp[left_nodes] * dp[right_nodes];
                //         n
                // dp[n] = ∑ ​dp[root−1] × dp[n−root]
                //         root=1
            }
        }

        return dp[n];
    }
};

/*
//         n
// dp[n] = ∑ ​dp[root−1] × dp[n−root]
//         root=1

dp[4]

= dp[0] × dp[3]
+ dp[1] × dp[2]
+ dp[2] × dp[1]
+ dp[3] × dp[0]

= 1×5 + 1×2 + 2×1 + 5×1

= 14
*/