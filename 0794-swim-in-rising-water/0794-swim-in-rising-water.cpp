class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int time = top[0];
            int r = top[1];
            int c = top[2];

            if(r == n - 1 && c == n - 1) 
                return time;

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    pq.push({max(time, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};
