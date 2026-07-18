class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            maxi = max(maxi,nums[i]);
            mini = min(mini,nums[i]);
        }

        int larGcd = INT_MIN;
        for(int i = 1; i <= mini; i++){
            if(maxi % i == 0 && mini % i == 0){
                larGcd = max(larGcd,i);
            }
        }

        return larGcd;
    }
};