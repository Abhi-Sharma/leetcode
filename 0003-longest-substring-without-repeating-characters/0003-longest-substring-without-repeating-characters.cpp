class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<int, int> mpp;
        int l = 0;
        int r = 0;
        int len = 0;
        while(r < n){
            if(mpp.find(s[r]) != mpp.end()){
                l = max(mpp[s[r]] + 1, l);
            }
            mpp[s[r]] = r;
            len = max(len, r - l + 1);
            r++;
        }
        return len;
    }
};