class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> left, right, equal;

        for(int i = 0; i < n; i++){
            if(nums[i] < pivot) left.push_back(nums[i]);
            else if(nums[i] == pivot) equal.push_back(nums[i]);
            else right.push_back(nums[i]);
        }


        vector<int> ans;
        for(int x : left) ans.push_back(x);
        for(int x : equal) ans.push_back(x);
        for(int x : right) ans.push_back(x);

        return ans;
    }
};