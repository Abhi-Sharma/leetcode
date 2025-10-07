class Solution {
    private:
    int maxEl(vector<int> piles){
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    long long calculateHr(vector<int> piles, int hour){
        long long totalhr = 0;
        for(int i = 0; i < piles.size(); i++){
            totalhr += ceil((double)piles[i]/hour);
        }
        return totalhr;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = maxEl(piles);
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;
            long long totalhr = calculateHr(piles,mid);
            if(totalhr <= h){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};