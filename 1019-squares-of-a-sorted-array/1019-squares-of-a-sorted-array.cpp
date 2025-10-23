class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0;
        int right = n - 1;
        int k = n - 1;
        while(left <= right){
            int leftsqr = nums[left] * nums[left];
            int rightsqr = nums[right] * nums[right];
            if(leftsqr > rightsqr){
                ans[k] = leftsqr;
                k--;
                left++;
            }
            else{
                ans[k] = rightsqr;
                k--;
                right--;
            }
        }
        return ans;
    }
};