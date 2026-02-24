class Solution {
public:
int oddsub(vector<int>& nums, int k){
    int n = nums.size();
    int l = 0, r = 0, odd = 0, cnt = 0;
    while(r < n){
        if(nums[r] % 2 != 0) odd++;
        while(odd > k){
            if(nums[l] % 2 != 0) odd--;
            l++;
        }
        if(odd <= k){
            cnt += (r-l+1);
        }
        r++;
    }
    return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt = oddsub(nums,k) - oddsub(nums,k-1);
        return cnt;
    }
};