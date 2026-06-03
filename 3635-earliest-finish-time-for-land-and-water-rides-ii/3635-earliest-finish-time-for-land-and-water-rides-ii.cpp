class Solution {
public:
int solve(vector<int>& A, vector<int>& AD, vector<int>& B, vector<int>& BD){
    int m = B.size();
    vector<pair<int,int>> rides;

    for(int i = 0; i < m; i++){
        rides.push_back({B[i],BD[i]});
    }
    sort(rides.begin(),rides.end());
    vector<int> starts(m);

    for(int i = 0; i < m; i++){
        starts[i] = rides[i].first;
    }

    vector<int> pref(m);
    pref[0] = rides[0].second;
    for(int i = 1; i < m; i++){
        pref[i] = min(pref[i-1], rides[i].second);
    }

    vector<int> suff(m);
    suff[m-1] = rides[m-1].first + rides[m-1].second;

    for(int i = m - 2; i >= 0; i--){
        suff[i] = min(suff[i+1], rides[i].first + rides[i].second);
    }

    int ans = INT_MAX;
    for(int i = 0; i < A.size(); i++){
        int T = A[i] + AD[i];

        int idx = upper_bound(
                starts.begin(),
                starts.end(),
                T
            ) - starts.begin() - 1;

        if(idx >= 0){
            ans = min(ans, T + pref[idx]);
        }
        if(idx + 1 < m){
            ans = min(ans, suff[idx + 1]);
        }
    }
    return ans;
}
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans1 = solve(landStartTime,landDuration,waterStartTime,waterDuration);

        
        int ans2 = solve(waterStartTime,waterDuration,landStartTime,landDuration);

        return min(ans1, ans2);
    }
};