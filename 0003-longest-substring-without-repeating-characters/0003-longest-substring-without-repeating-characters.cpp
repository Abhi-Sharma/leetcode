class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<bool> vis(256, false);
        int left = 0;
        int right = 0;
        int maxLen = 0;

        while(right < n){
            while(vis[s[right]] == true){
                vis[s[left]] = false;
                left++;
            }
            vis[s[right]] = true;
            maxLen = max(maxLen,right - left + 1);
            right++;
        }
        return maxLen;
    }
};