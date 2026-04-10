class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
        int ans = INT_MAX;

        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);

            auto& v = mpp[nums[i]];
            int sz = v.size();

            if(sz >= 3){
                int k = v[sz - 1];
                int i_index = v[sz - 3];
                ans = min(ans, 2 * (k - i_index));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};