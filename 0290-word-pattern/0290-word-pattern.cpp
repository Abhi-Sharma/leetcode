class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        stringstream ss(s);

        for(int i = 0; i < pattern.size(); i++){
            char ch = pattern[i];
            string temp = "";
            
            if(!getline(ss, temp, ' ')) return false;
            
            
            if(mp1.count(ch) && mp1[ch] != temp) return false;
            if(mp2.count(temp) && mp2[temp] != ch) return false;

            mp1[ch] = temp;
            mp2[temp] = ch;
        }

        string extra;
        if(ss >> extra)
            return false;
        return true;
    }
};