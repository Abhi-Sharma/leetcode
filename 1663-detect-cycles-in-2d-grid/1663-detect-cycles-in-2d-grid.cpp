class Solution {
    bool dfs(int row, int col, int pr, int pc, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
            && grid[nrow][ncol] == grid[row][col]){
                if(!vis[nrow][ncol]){
                if(dfs(nrow,ncol,row,col,vis,grid) == true) return true;
                }
                 else if(nrow != pr || ncol != pc) return true;
            }
           
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    if(dfs(i,j,-1,-1,vis,grid) == true) return true;
                }
            }
        }
        return false;
    }
};