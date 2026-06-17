class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        long long len = 0;

        for(int i = 0; i < n; i++){
            char ch = s[i];

            if(ch == '#') len *= 2;
            else if(ch == '*'){
                if(len > 0) len--;
            }
            else if(ch == '%'){
                continue;
            }
            else len++;
        }

        if(k >= len) return '.';

        for(int i = n - 1; i >= 0; i--){
            char ch = s[i];

            if(ch == '#'){
                len = len/2;
                if(k >= len) k -= len;
            }
            else if(ch == '%'){
                k = len - k - 1;
            }
            else if(ch == '*') len++;
            else len--;
            if(len == k) return ch;
        }
        return '.';
    }
};