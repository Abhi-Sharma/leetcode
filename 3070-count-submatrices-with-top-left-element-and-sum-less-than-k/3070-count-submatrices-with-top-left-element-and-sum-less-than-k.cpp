class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int up = (i > 0) ? grid[i-1][j] : 0;
                int left = (j > 0) ? grid[i][j-1] : 0;
                int diag = (i > 0 && j > 0) ? grid[i-1][j-1] : 0;

                grid[i][j] = grid[i][j] + up + left - diag;

                if(grid[i][j] <= k) count++;

            }
        }
        return count;
    }
};