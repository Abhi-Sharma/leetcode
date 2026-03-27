class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        int shift = k % m;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int newCol;
                
                if(i % 2 == 0) {
                    newCol = (j + shift) % m;
                } else {
                    newCol = (j - shift + m) % m;
                }
                if(mat[i][j] != mat[i][newCol]) {
                    return false;
                }
            }
        }

        return true;
    }
};