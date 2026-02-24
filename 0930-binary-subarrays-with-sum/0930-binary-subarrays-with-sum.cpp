class Solution {
public:
int minSub(vector<int>& nums, int goal){
    if(goal < 0) return 0;
    int n = nums.size();
    int l = 0, r = 0, sum = 0, cnt = 0;
    while(r < n){
        sum += nums[r];
        while(sum > goal){
            sum -= nums[l];
            l++;
        }
        if(sum <= goal){
            cnt += (r - l + 1);
        }
        r++;
    }
    return cnt;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = minSub(nums,goal) - minSub(nums,goal-1);
        return cnt;
    }
};