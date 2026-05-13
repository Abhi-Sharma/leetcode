class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2 * limit + 2, 0);

        int low = 0;
        int high = 0;
        for(int i = 0; i < n/2; i++){
            int a = nums[i];
            int b = nums[n - i - 1];

            int sum = a + b;
            int low = min(a,b) + 1;
            int high = max(a,b) + limit;

            diff[2] += 2;
            diff[low] -= 1;
            diff[high + 1] += 1;

            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = INT_MAX;
        int curr = 0;
        for(int target = 2; target <= 2*limit; target++){
            curr += diff[target];
            ans = min(ans,curr);
        }
        return ans;
    }
};