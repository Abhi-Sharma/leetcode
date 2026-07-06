class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(),intervals.end(),[](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int ans = 1;
        int maxEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][1] <= maxEnd) {
                
            } else {
                ans++;
                maxEnd = intervals[i][1];
            }
        }

        return ans;
    }
};