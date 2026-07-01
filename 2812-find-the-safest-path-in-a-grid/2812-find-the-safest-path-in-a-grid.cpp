class Solution {
public:
bool canReach(vector<vector<int>>& dist, int safe) {

    int n = dist.size();

    if(dist[0][0] < safe)
        return false;

    queue<pair<int,int>> q;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    q.push({0,0});
    vis[0][0] = 1;

    while(!q.empty()) {

        auto curr = q.front();
        q.pop();

        int r = curr.first;
        int c = curr.second;

        if(r == n-1 && c == n-1)
            return true;

        for(int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < n &&
               !vis[nr][nc] &&
               dist[nr][nc] >= safe) {

                vis[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }

    return false;
}
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n,-1));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    dist[i][j] = 0;
                } 
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = dr[i] + r;
                int nc = dc[i] + c;

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1){
                    dist[nr][nc] = 1 + dist[r][c];
                    q.push({nr,nc});
                }
            }
        }

        int low = 0;
        int high = 2 * (n - 1);
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canReach(dist,mid)){
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return high;
    }
};