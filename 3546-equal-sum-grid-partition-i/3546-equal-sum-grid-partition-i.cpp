class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long totalSum = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) totalSum += grid[i][j];
        }

        if(totalSum % 2 != 0) return false;
        long long half = totalSum / 2;

        long long currSum = 0;
        for(int i = 0; i < m-1; i++){
            for(int j = 0; j < n; j++) currSum += grid[i][j];
            if(currSum == half) return true;
        }

        currSum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) currSum += grid[i][j];
            if (currSum == half) return true;
        }

        return false;
    }
};