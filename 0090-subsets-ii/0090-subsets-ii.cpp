class Solution {
    void subs(int ind, vector<int>& res, vector<int>& nums, vector<vector<int>>& ans){
        ans.push_back(res);
         for(int i = ind; i < nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]) continue;
        res.push_back(nums[i]);
        subs(i+1,res,nums,ans);
        res.pop_back();
    }
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        subs(0,res,nums,ans);
        return ans;
    }
};