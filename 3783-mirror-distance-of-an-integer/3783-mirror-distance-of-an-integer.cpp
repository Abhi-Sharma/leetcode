class Solution {
public:
int reve(int n){
    int ans = 0;

    while(n){
        int rem = n % 10;
        ans = ans * 10 + rem;
        n /= 10;
    }
    return ans;
}
    int mirrorDistance(int n) {
        int rev = reve(n);
        return abs(n - rev);
    }
};