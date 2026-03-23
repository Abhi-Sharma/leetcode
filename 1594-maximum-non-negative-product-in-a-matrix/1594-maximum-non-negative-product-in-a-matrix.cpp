class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const long mod = 1e9 + 7;

        vector<vector<long long>> dpMax(m, vector<long long>(n));
        vector<vector<long long>> dpMin(m, vector<long long>(n));

        dpMax[0][0] = dpMin[0][0] = grid[0][0];
        
        for(int i = 1; i < m; i++){
            long long val = grid[i][0];
            dpMax[i][0] = dpMax[i-1][0] * val;
            dpMin[i][0] = dpMin[i-1][0] * val;
        }

        for(int j = 1; j < n; j++){
            long long val = grid[0][j];
            dpMax[0][j] = dpMax[0][j-1] * val;
            dpMin[0][j] = dpMin[0][j-1] * val;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                long long val = grid[i][j];

                long long a = dpMax[i][j-1] * val;
                long long b = dpMin[i][j-1] * val;
                long long c = dpMax[i-1][j] * val;
                long long d = dpMin[i-1][j] * val;


                dpMax[i][j] = max({a,b,c,d});
                dpMin[i][j] = min({a,b,c,d});
            }
        }

        long long ans = dpMax[m-1][n-1];
        if(ans < 0) return -1;

        return ans % mod;
    }
};