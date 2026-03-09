class Solution {
public:
int countSubset(vector<int>& nums, int sum, int n){
    int dp[n+1][sum+1];
    dp[0][0] = 1;
    for(int j = 1; j < sum+1; j++) dp[0][j] = 0;

    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < sum+1; j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;

        
        for(int s : nums) sum += s;

        if(abs(target) > sum) return 0;
        if((target + sum) % 2 != 0) return 0;
        int s1 = (target + sum)/2;

        return countSubset(nums,s1,n);
    }
};