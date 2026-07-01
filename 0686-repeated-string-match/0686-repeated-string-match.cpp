class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        int cnt = 0;

        string s = "";
        while(s.size() < m){
            s += a;
            cnt++;
        }

        if(s.find(b) != string::npos) return cnt;

        s += a;

        if(s.find(b) != string::npos) return cnt + 1;

        return -1;
    }
};