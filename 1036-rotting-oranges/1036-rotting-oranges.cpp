class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
            }
        }
        int count = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            count = max(time,count);

            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 2;
                    q.push({{nrow,ncol}, time + 1});
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] != 2){
                    return -1;
                }
            }
        }
        return count;
    }
};