class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x){
            long long digit = x % 10;
            ans = ans * 10 + digit;

            if (ans > INT_MAX || ans < INT_MIN) return 0;
            x /= 10;
        }
        return ans;
    }
};