class Solution {
    private:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0;
        int bloomcnt = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day) cnt++;
            else{
                bloomcnt += (cnt/k);
                cnt = 0;
            }
        }
        bloomcnt += (cnt/k);
        return bloomcnt >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = (long long) m * (long long) k;
        if(val > n) return -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            mini = min(bloomDay[i],mini);
            maxi = max(bloomDay[i],maxi);
        }
        int low = mini;
        int high = maxi;
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(possible(bloomDay,mid,m,k) == true){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};