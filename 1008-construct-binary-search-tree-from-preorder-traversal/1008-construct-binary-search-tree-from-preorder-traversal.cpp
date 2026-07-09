class Solution {
public:
    int i = 0;

    TreeNode* build(vector<int>& preorder, int bound) {
        if (i == preorder.size() || preorder[i] > bound)
            return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);

        root->left = build(preorder, root->val);
        root->right = build(preorder, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};