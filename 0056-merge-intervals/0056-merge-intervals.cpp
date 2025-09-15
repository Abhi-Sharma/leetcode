class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int currentTime = intervals[0][0];
        int lasttime = intervals[0][1];
        for(int i = 1 ; i < intervals.size(); i++){
            if(intervals[i][0] <= lasttime){
                lasttime = max(lasttime, intervals[i][1]);
            }
            else{
                res.push_back({currentTime, lasttime});
                currentTime = intervals[i][0];
                lasttime = intervals[i][1];
            }
        }
         res.push_back({currentTime,lasttime});
         return res;
    }
};