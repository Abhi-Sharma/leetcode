class Solution {
    private:
    bool canShip(vector<int>& weights, int w, int days){
        int currentload = 0;
        int daysNeeded = 1;
        for(int i = 0; i < weights.size(); i++){
            if(currentload + weights[i] > w){
                daysNeeded++;
                currentload = 0;
            }
            currentload += weights[i];
        }
        return daysNeeded <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0 , maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi,weights[i]);
            sum += weights[i];
        }
        int low = maxi;
        int high = sum;
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(canShip(weights,mid,days) == true){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};