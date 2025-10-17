class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();
        int r = 0;
        int l = 0;
        while(r < m && l < n){
            if(g[l] <= s[r]){
                l = l + 1;
            }
            r = r + 1;
        }
        return l;
    }
};