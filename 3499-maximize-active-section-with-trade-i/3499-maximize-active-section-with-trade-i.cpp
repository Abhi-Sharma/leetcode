class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int totalOnes = 0;
        for(char ch : s){
            if(ch == '1') totalOnes++;
        }

        string t = "1" + s + "1";

        int cnt = 1;
        vector<pair<char,int>> blocks;
        for(int i = 1; i < t.size(); i++){
            if(t[i] == t[i-1]) cnt++;
            else{
                blocks.push_back({t[i-1],cnt});
                cnt = 1;
            }
        }

        blocks.push_back({t.back(), cnt});
        int gain = 0;
        for(int i = 1; i + 1< blocks.size(); i++){
            if(blocks[i].first == '1' && blocks[i-1].first == '0' && blocks[i+1].first == '0'){
                gain = max(gain, blocks[i-1].second + blocks[i+1].second);
            }
        }


        return totalOnes + gain;
    }
};