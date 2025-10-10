class Solution {
    bool divide(vector<int>& nums, int divisor, int threshold){
        int sum = 0;
        for(int num : nums){
            sum += (num + divisor - 1) / divisor; //(for my reference sum += ceil(num/divisor))
        }
        return sum <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi,nums[i]);
        }
        int low = 1;
        int high = maxi;
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(divide(nums,mid,threshold) == true){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};