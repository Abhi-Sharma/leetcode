class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<bool> ans;

        vector<int> prefix(n, 0);

        for (int i = 0; i < n - 1; i++) {
            prefix[i] = (abs(nums[i] - nums[i + 1]) > maxDiff);
        }

        for (int i = 1; i < n; i++)
            prefix[i] += prefix[i - 1];

        for(int q = 0; q < m; q++){
            int i = queries[q][0];
            int j = queries[q][1];

            if(i > j) swap(i,j);
            if (i == j) {
                ans.push_back(true);
                continue;
            }
            int badEdges = prefix[j - 1] - (i == 0 ? 0 : prefix[i - 1]);
            ans.push_back(badEdges == 0);
        }
        return ans;
    }
};