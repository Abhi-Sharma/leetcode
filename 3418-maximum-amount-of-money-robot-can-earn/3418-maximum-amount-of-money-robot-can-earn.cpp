class Solution {
public:
int t[501][501][3];
int solve(vector<vector<int>>& coins, int m, int n, int i, int j, int neu){
    if(i == m-1 && j == n-1){
        if(coins[i][j] < 0 && neu > 0){
            return 0;
        }
        return coins[i][j];
    }
    if(i >= m || j >= n) return INT_MIN;

    if(t[i][j][neu] != INT_MIN) return t[i][j][neu];

    int take = coins[i][j] + max(solve(coins,m,n,i+1,j,neu),solve(coins,m,n,i,j+1,neu));

    int skip = INT_MIN;
    if(coins[i][j] < 0 && neu > 0){
        int skipDown = solve(coins,m,n,i+1,j,neu - 1);
        int skipRight = solve(coins,m,n,i,j+1,neu - 1);
        skip = max(skipDown,skipRight);
    }
   return t[i][j][neu] = max(take,skip);
}
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        for(int i = 0; i < 501; i++){
            for(int j = 0; j < 501; j++){
                for(int k = 0; k < 3; k++){
                    t[i][j][k] = INT_MIN;
                }
            }
        }
        int ans = solve(coins,m,n,0,0,2);
        return ans;
    }
};