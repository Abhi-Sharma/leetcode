class Solution {
    bool anagrams(string a, string b){
        if(a.size() != b.size()) return false;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a == b;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        int i = 0;
        for(int j = 1; j < n; j++){
            if(!anagrams(words[i],words[j])){
                i++;
                words[i] = words[j];
            }
        }
        words.resize(i + 1);
        return words;
    }
};