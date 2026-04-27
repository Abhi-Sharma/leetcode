class Solution {
public:
vector<vector<pair<int,int>>> dir = {
    {},
    {{0,-1},{0,1}},
    {{-1,0},{1,0}},
    {{0,-1},{1,0}},
    {{0,1},{1,0}},
    {{0,-1},{-1,0}},
    {{0,1},{-1,0}}
};
bool valid(int x, int y, int m, int n){
    return x >= 0 && y >= 0 && x < m && y < n;
}
bool dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();

    if(r == m-1 && c == n-1) return true;
    vis[r][c] = 1;
    for(auto [dx,dy] : dir[grid[r][c]]){
        int nr = r + dx;
        int nc = c + dy;

        if(!valid(nr,nc,m,n) || vis[nr][nc]) continue;
        for(auto [rdx,rdy] : dir[grid[nr][nc]]){
            if(rdx + nr == r && rdy + nc == c){
                if(dfs(nr,nc,vis,grid)) return true;
            }
        }
    }
    return false;
}
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));

        return dfs(0,0,vis,grid);
    }
};