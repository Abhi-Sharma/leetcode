class Solution{
public:
    bool check(const vector<int>& isIncreasing, int k) {
        int n = isIncreasing.size();
        for (int i = 0; i <= n - 2 * k; ++i) {
            if (isIncreasing[i] >= k && isIncreasing[i + k] >= k) {
                return true;
            }
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> isIncreasing(n, 1);

        // Precompute lengths of increasing subarrays
        for (int i = n-2; i >=0; --i) {
            if (nums[i+1] > nums[i]) {
                isIncreasing[i] = isIncreasing[i + 1] + 1;
            }
        }

        int low = 1, high = n, ans = 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(isIncreasing, mid)) {
                ans = max(ans, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
}; 