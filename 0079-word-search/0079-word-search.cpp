class Solution {
public:
bool dfs(int row, int col, vector<vector<char>>& board, string& word, int k){
    if(k == word.size()) return true;
    int delrow[] = {-1,0,1,0};
    int delcol[] = {0,1,0,-1};
    int m = board.size();
    int n = board[0].size();
    if(row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[k]) return false;

    char temp = board[row][col];
    board[row][col] = '#';
    for(int i = 0; i < 4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if(dfs(nrow,ncol,board,word,k+1)) return true;
    }
    board[row][col] = temp;
    return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(word[0] == board[i][j]){
                    if(dfs(i,j,board,word,0) == true) return true;
                }
            }
        }
        return false;;
    }
};