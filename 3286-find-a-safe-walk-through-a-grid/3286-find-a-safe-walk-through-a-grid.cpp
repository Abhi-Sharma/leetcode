class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> best(n, vector<int>(m,-1));
        queue<tuple<int,int,int>> q;
        if(grid[0][0] == 1){
            health -= 1;
        }
        if(health < 1) return false;
        q.push({0,0,health});
        best[0][0] = health;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
           auto [r, c, h] = q.front();

            q.pop();
            if(r == n-1 && c == m-1) return true;
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                int newhealth = h - grid[nr][nc];
                if(newhealth <= 0) continue;

                
                if(newhealth > best[nr][nc]){ 
                    q.push({nr,nc,newhealth});
                    best[nr][nc] = newhealth;
                }
                
            }
        }
        return false;
    }
};