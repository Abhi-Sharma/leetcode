class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r= 0;
        vector<int> hash(26,0);
        int maxlen = 0;
        int maxf = 0;
        while(r < n){
            hash[s[r] - 'A']++;
            maxf = max(maxf,hash[s[r] - 'A']);
            if((r-l+1) - maxf > k){
                hash[s[l] - 'A']--;
                maxf = 0;
                l++;
            }
            if((r-l+1) - maxf <= k){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};