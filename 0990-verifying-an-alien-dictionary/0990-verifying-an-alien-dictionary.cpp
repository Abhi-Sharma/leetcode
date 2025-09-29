class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26, 0);
        for (int i = 0; i < order.size(); i++) {
            rank[order[i] - 'a'] = i;
        }
        for(int i = 0; i < words.size() - 1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(),s2.size());
            bool valid = false;
            for(int ptr = 0; ptr < len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    if (rank[s1[ptr] - 'a'] > rank[s2[ptr] - 'a']) return false;
                    valid = true;
                    break;
                }
            }
            if(!valid && s1.size() > s2.size()) return false;
        }
        return true;
        
    }
};