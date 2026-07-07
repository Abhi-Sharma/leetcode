class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string s = to_string(n);
        int m = s.size();

        string res = "";
        int sum = 0;
        for(int i = 0; i < m; i++){
            if(s[i] != '0') {
                res += s[i];
                sum += s[i] - '0';
            }
        }

        int num = stoi(res);

        return 1LL * num * sum;
    }
};