class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        int j = n - 1;
        for(int i = 0; i < n; i++){
           if(colors[i] != colors[0]) ans = max(ans, i);
           if(colors[i] != colors[j]) ans = max(ans, abs(i - j));
        }
        return ans;
    }
};