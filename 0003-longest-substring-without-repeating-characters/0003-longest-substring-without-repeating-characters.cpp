class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        map<int,int> mpp;
        int maxlen = 0;
        while(r < n){
            if(mpp.find(s[r]) != mpp.end()){
                if(mpp[s[r]] >= l){
                    l = mpp[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxlen = max(len,maxlen);
            mpp[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};