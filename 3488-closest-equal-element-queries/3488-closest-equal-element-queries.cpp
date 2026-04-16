class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
        }
        vector<int> ans;

        for(int q : queries){
            int val = nums[q];
            vector<int>& vec = mpp[val];

            if(vec.size() == 1){
                ans.push_back(-1);
                continue;
            }
            int sz = vec.size();
            auto it = lower_bound(vec.begin(),vec.end(), q);
            int idx = it - vec.begin();

            int left = vec[(idx - 1 + sz) % sz];
            int right = vec[(idx + 1) % sz];

            int d1 = abs(q - left);
            d1 = min(d1, n - d1);

            int d2 = abs(q - right);
            d2 = min(d2, n - d2);

            ans.push_back(min(d1,d2));
        }
        return ans;
    }
};