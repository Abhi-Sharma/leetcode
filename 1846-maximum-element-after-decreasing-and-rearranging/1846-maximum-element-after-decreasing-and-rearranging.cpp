class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        
        sort(arr.begin(),arr.end());
        arr[0] = 1;
        int maxi = arr[0];

        for(int i = 1; i < n; i++){
            if(abs(arr[i] - arr[i-1]) <= 1){
                maxi = max(maxi,arr[i]);
            }
            else{
                int res = arr[i] - arr[i-1];
                arr[i] = arr[i] - res + 1;
                maxi = max(maxi,arr[i]);
            }
        }
        return maxi;
    }
};