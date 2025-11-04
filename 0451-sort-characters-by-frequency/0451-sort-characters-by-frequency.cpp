class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char ch : s){
            freq[ch]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto ch : freq){
            pq.push({ch.second,ch.first});
        }

        string ans = "";
        while(!pq.empty()){
            char ch = pq.top().second;
            int count = pq.top().first;
            pq.pop();
            ans.append(count,ch);
        }
        return ans;
    }
};