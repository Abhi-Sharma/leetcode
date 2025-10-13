class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int currentStart = intervals[0][0];
        int lastTime = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= lastTime){
                lastTime = max(lastTime,intervals[i][1]);
            }
            else{
                ans.push_back({currentStart,lastTime});
                currentStart = intervals[i][0];
                lastTime = intervals[i][1];
            }
        }
        ans.push_back({currentStart,lastTime});
        return ans;
    }
};