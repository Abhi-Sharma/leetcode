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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int first = 0;
        int last = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                unsigned long long ind = q.front().second;
                q.pop();
                if(i == 0) first = ind;
                if(i == size-1) last = ind;
                if(node->left) q.push({node->left,ind*2+1});
                if(node->right) q.push({node->right,ind*2+2});
            }
            ans = max(ans,last - first + 1);
        }
        return ans;
    }
};