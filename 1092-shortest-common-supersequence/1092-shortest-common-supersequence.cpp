class Solution {
public:
string LCS(string str1, string str2){
    int n = str1.size();
    int m = str2.size();

    int dp[n+1][m+1];
    for(int i = 0; i < n+1; i++) dp[i][0] = 0;
    for(int j = 0; j < m+1; j++) dp[0][j] = 0;

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    int i = n; 
    int j = m;

    string ans = "";
    while(i > 0 && j > 0){
        if(str1[i-1] == str2[j-1]){ 
            ans.push_back(str1[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i][j - 1] > dp[i-1][j]) j--;
            else i--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = LCS(str1,str2);
        int i = 0;
        int j = 0;
        string ans = "";

        for(char ch : lcs){
            while(str1[i] != ch){
                ans.push_back(str1[i]);
                i++;
            }
            while(str2[j] != ch){
                ans.push_back(str2[j]);
                j++;
            }

            ans.push_back(ch);
            i++;
            j++;
        }
        ans += str1.substr(i);
        ans += str2.substr(j);

        return ans;
    }
};