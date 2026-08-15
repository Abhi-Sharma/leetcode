class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;
        int right = 0;

        int maxi = INT_MIN;
        long long sum = 0;

        while(right < n){
            sum += nums[right];

            while((long long)nums[right] * (right - left + 1) - sum > k){
                sum -= nums[left];
                left++;
            }
            maxi = max(maxi,right - left + 1);
            right++;
        }
        return maxi;
    }
};