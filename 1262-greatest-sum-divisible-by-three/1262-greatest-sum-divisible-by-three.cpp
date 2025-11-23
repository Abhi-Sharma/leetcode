class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;

        int r1a = INT_MAX, r1b = INT_MAX;
        int r2a = INT_MAX, r2b = INT_MAX;

        for (int x : nums) {
            sum += x;
            if (x % 3 == 1) {
                if (x < r1a) { r1b = r1a; r1a = x; }
                else if (x < r1b) { r1b = x; }
            } 
            else if (x % 3 == 2) {
                if (x < r2a) { r2b = r2a; r2a = x; }
                else if (x < r2b) { r2b = x; }
            }
        }

        if (sum % 3 == 0) return sum;

        if (sum % 3 == 1) {
            int remove1 = r1a;
            int remove2 = (r2a == INT_MAX || r2b == INT_MAX ? INT_MAX : r2a + r2b);
            int remove = min(remove1, remove2);
            return remove == INT_MAX ? 0 : sum - remove;
        }

        int remove1 = r2a;
        int remove2 = (r1a == INT_MAX || r1b == INT_MAX ? INT_MAX : r1a + r1b);
        int remove = min(remove1, remove2);
        return remove == INT_MAX ? 0 : sum - remove;
    }
};
