class Solution {
public:
    int fib(int n) {
        if(n == 1) return 1;
        int a = 0;
        int b = 1;
        int temp = 0;
        for(int i = 2; i <= n; i++){
            temp = a + b;
            a = b;
            b = temp;
        }
        return temp;
    }
};