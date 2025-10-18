class Solution {
    void subs(int ind, vector<int>& res, vector<int>& nums, vector<vector<int>>& ans){
        if(ind >= nums.size()){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[ind]);
        subs(ind+1,res,nums,ans);
        res.pop_back();
        subs(ind+1,res,nums,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        subs(0,res,nums,ans);
        return ans;
    }
};