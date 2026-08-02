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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;

        TreeNode* prev = NULL;
        TreeNode* curr = root;

        int ans = INT_MAX;
        while(curr != NULL || !st.empty()){
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            if(prev != NULL) ans = min(ans,curr->val - prev->val);

            prev = curr;
            curr = curr->right;
        }
        return ans;
    }
};