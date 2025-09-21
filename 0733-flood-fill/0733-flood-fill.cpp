class Solution {
    void dfs(int sr, int sc, vector<vector<int>>& image, int color, int iniColor){
        image[sr][sc] = color;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i < 4; i++){
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && image[nrow][ncol] == iniColor && 
            image[nrow][ncol] != color){
                dfs(nrow,ncol,image,color,iniColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        dfs(sr,sc,image,color,iniColor);
        return image;
    }
};