class Solution {
    long long reverse(int x){
        long long ans = 0;
        while(x){
            long long last = x % 10;
            ans = ans * 10 + last;
            x = x/10;
        }
        return ans;
    }
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long ans = reverse(x);
        if( x == ans) return true;
        return false;
    }
};