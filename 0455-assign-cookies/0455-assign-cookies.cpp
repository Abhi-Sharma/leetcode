class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int l = 0;
        int r = 0;
        int n = g.size();
        int m = s.size();
        while(l < n && r < m){
            if(g[l] <= s[r]){
                l++;
            }
            r++;
        }
        return l;
    }
};