class Solution {
public:
int LCS(string a, string b, int n, int m){
    int dp[n+1][m+1];

    for(int i = 0; i < n+1; i++) dp[i][0] = 0;
    for(int j = 0; j < m+1; j++) dp[0][j] = 0;

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int lcs = LCS(word1,word2,n,m);

        return ((n - lcs) + (m - lcs));
    }
};