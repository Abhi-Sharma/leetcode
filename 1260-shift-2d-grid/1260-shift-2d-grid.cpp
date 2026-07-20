class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int p = n * m;
        k = k % p;
        if(k == 0) return grid;
        
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                int idx = (i * m) + j;

                int newidx = (idx + k) % p;

                int newrow = newidx / m;
                int newcol = newidx % m;
                ans[newrow][newcol] = grid[i][j];
            }
        }
        return ans;
    }
};