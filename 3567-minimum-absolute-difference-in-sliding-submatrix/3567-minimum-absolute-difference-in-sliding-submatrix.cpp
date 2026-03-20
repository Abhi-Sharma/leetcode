class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        for(int x = 0; x <= m - k; x++){
            for(int y = 0; y <= n - k; y++){

                vector<int> vec;
                for(int i = x; i < x + k; i++){
                    for(int j = y; j < y + k; j++){
                        vec.push_back(grid[i][j]);
                    }
                }

                int mini = INT_MAX;
                sort(vec.begin(),vec.end());
                vec.erase(unique(vec.begin(), vec.end()), vec.end());
                for(int t = 1; t < vec.size(); t++){
                    mini = min(mini, (vec[t] - vec[t-1]));
                }

                ans[x][y] = (mini == INT_MAX ? 0 : mini);
            }
        }
        return ans;
    }
};