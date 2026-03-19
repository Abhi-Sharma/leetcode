class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ps(n, vector<int>(m, 0));
        vector<vector<int>> countX(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'X') ps[i][j] = 1;
                else if(grid[i][j] == 'Y') ps[i][j] = -1;
                else ps[i][j] = 0;

                countX[i][j] = (grid[i][j] == 'X');

                int up = (i > 0) ? ps[i-1][j] : 0;
                int left = (j > 0) ? ps[i][j-1] : 0;
                int diag = (i > 0 && j > 0) ? ps[i-1][j-1] : 0;

                int upX = (i > 0) ? countX[i-1][j] : 0;
                int leftX = (j > 0) ? countX[i][j-1] : 0;
                int diagX = (i > 0 && j > 0) ? countX[i-1][j-1] : 0;

                ps[i][j] = ps[i][j] + up + left - diag;
                countX[i][j] = countX[i][j] + upX + leftX - diagX;

                if(ps[i][j] == 0 && countX[i][j] > 0) cnt++;
            }
        }
        return cnt;
    }
};