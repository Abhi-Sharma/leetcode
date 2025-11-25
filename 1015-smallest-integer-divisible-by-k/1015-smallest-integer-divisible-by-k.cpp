class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        int rem = 1 % k;
        int len = 1;
        while(rem != 0){
            rem = (rem * 10 + 1) % k;
            len++;
        }
        return len;
    }
};