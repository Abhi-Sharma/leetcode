class Solution {
public:
int ksub(vector<int>& nums, int k){
    if(k == 0) return 0;
    int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        unordered_map<int,int> freq;
        while(r < n){
            if(freq[nums[r]] == 0) k--;
            freq[nums[r]]++;

            while(k < 0){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) k++;
                l++;
            }
            if(k >= 0){
                cnt += (r - l + 1);
            }
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int cnt = ksub(nums,k) - ksub(nums,k-1);
        return cnt;
    }
};