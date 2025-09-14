class Solution {
public:
static bool comp(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 1;
        int lastTime = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= lastTime){
                cnt++;
                lastTime = intervals[i][1];
            }
        }
        return n - cnt;
    }
};