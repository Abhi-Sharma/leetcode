class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            count = 0;
            for(int j = i; j < n; j++){
                if(nums[j] == target) count++;
                int len = j - i + 1;
                if(2 * count > len) ans++;
             }
        }
        return ans;
    }
};