class Solution {
public:
void rotateArray(vector<int>& arr, int k){
    int n = arr.size();
    k %= n;

    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m,n) / 2;

        for(int layer = 0; layer < layers; layer++){
            vector<int> arr;

            int top = layer;
            int right = n - layer - 1;
            int bottom = m - layer - 1;
            int left = layer;

            for(int i = left; i <= right; i++){
                arr.push_back(grid[top][i]);
            }

            for(int i = top + 1; i <= bottom; i++){
                arr.push_back(grid[i][right]);
            }

            for(int i = right - 1; i >= left; i--){
                arr.push_back(grid[bottom][i]);
            }

            for(int i = bottom - 1; i > top; i--){
                arr.push_back(grid[i][left]);
            }

            rotateArray(arr,k);

            int idx = 0;

            for(int i = left; i <= right; i++){
                grid[top][i] = arr[idx++];
            }

            for(int i = top + 1; i <= bottom; i++){
                grid[i][right] = arr[idx++];
            }

            for(int i = right - 1; i >= left; i--){
                grid[bottom][i] = arr[idx++];
            }

            for(int i = bottom - 1; i > top; i--){
                grid[i][left] = arr[idx++];
            }
        }
        return grid;
    }
};