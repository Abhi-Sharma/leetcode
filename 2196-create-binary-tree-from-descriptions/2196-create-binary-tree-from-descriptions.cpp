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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> childs;

        for(auto &d : descriptions){
            int parent = d[0];
            int child = d[1];
            int left = d[2];

            if(mpp.find(parent) == mpp.end()) mpp[parent] = new TreeNode(parent);

            if(mpp.find(child) == mpp.end()) mpp[child] = new TreeNode(child);

            if(left == 1) mpp[parent]->left = mpp[child];
            else mpp[parent]->right = mpp[child];


            childs.insert(child);
        }

        for(auto it : mpp){
            if(childs.find(it.first) == childs.end()) return it.second;
        }

        return NULL;
    }
};