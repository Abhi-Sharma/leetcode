class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));;
        queue<pair<pair<int,int>,int>> q;
        int cntfresh = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else vis[i][j] = 0;
                if(grid[i][j] == 1) cntfresh++; 
            }
        }

        int t_max = 0;
        int cnt = 0;
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            t_max = max(t_max,t);

            for(int i = 0; i < 4; i++){
                int nrow = delrow[i] + r;
                int ncol = delcol[i] + c;
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && vis[nrow][ncol] != 2 && 
                grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }

        }
        if(cnt != cntfresh) return -1;
        return t_max;
    }
};