/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
struct Info{
    bool isBST;
    int minval;
    int maxval;
    int sum;
};
int ans = 0;
    Info solve(TreeNode* root) {
        if (root == NULL) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        if(left.isBST && right.isBST && left.maxval < root->val && root->val < right.minval){
            int currentsum = left.sum + right.sum + root->val;
            ans = max(ans,currentsum);
            return {true,
                min(left.minval, root->val),
                max(right.maxval, root->val),
                currentsum
            };
        }
        return {
            false,
            0,
            0,
            0
        };
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};