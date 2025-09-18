class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s1 = 0;
        int s2 = 0;
        for(int i = 0 ; i <= n ; i++){
            s1 += i;
        }
        for(int i = 0; i < n; i++){
            s2 += nums[i];
        }
         return s1-s2;
    }
};