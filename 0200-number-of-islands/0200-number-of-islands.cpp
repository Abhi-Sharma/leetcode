class Solution {
public:
void bfs(vector<vector<char>>& grid,vector<vector<int>>& vis, int row, int col,int n, int m){
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                vis[nrow][ncol] = 1;
                q.push({nrow,ncol});
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    bfs(grid,vis,i,j,n,m);
                }
            }
        }
        return cnt;
    }
};