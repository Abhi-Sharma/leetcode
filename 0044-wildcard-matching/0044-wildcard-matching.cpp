class Solution {
public:
    bool isMatch(string s, string p) {
        int l = 0;
        int r = 0;
        int star = -1;
        int match = -1;

        while(r < s.size()){
            if(l < p.size() && (p[l] == s[r] || p[l] == '?')){
                l++;
                r++;
            }
            else if(l < p.size() && p[l] == '*'){
                star = l;
                match = r;
                l++;
            }
            else if(star != -1){
                l = star + 1;
                match++;
                r = match;
            }
            else  return false;
        }

        while(l < p.size() && p[l] == '*') l++;

        return l == p.size();
    }
};