class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                int landStart = landStartTime[i] + landDuration[i];
                int landFinish = max(landStart, waterStartTime[j]);
                int res = landFinish + waterDuration[j];
                ans = min(ans,res);


                int waterStart = waterStartTime[j] + waterDuration[j];
                int waterFinish = max(waterStart, landStartTime[i]);
                int ress = waterFinish + landDuration[i];
                ans = min(ans,ress);
            }
        }
        return ans;
    }
};