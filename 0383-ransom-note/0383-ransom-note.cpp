class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();

        if(n > m) return  false;
        vector<int> freq(26,0);

        for(char ch : magazine) freq[ch - 'a']++;
        for(char ch : ransomNote){
            if(freq[ch - 'a'] == 0) return false;
            freq[ch - 'a']--;
        }
        return true;
    }
};