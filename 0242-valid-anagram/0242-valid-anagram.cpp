class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m != n) return false;

        int freq[26] = {0};
        for(int i = 0; i < m; i++) freq[s[i] - 'a']++;

        for(int i = 0; i < n; i++) freq[t[i] - 'a']--;

        for(int i = 0; i < n; i++) if(freq[t[i] - 'a'] != 0) return false;

        return true;
    }
};