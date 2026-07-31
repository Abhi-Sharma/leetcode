class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        int dr[] = {-1,-1,-1,0,1,1,1,0};
        int dc[] = {-1,0,1,1,1,0,-1,-1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int live = 0;

                for(int dis = 0; dis < 8; dis++){
                    int nr = i + dr[dis];
                    int nc = j + dc[dis];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < m && (board[nr][nc] == 1 || board[nr][nc] == -1))
                    live++;
                }

                if(board[i][j] == 1){
                    if(live < 2 || live > 3) board[i][j] = -1;
                }
                else{
                    if(live == 3) board[i][j] = 2;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == -1) board[i][j] = 0;
                if(board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};