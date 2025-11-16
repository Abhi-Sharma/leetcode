class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        long long count = 0;
        long long ans = 0;

        for(char c : s) {
            if(c == '1') {
                count++;                
                ans = (ans + count) % MOD;
            } else {
                count = 0;           
            }
        }

        return ans;
    }
};
