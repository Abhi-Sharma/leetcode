class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int max_freq = 0;
        for(int x : nums){
            freq[x]++;
            max_freq = max(max_freq,freq[x]);
        }
        int ans = 0;
        for(auto p : freq){
            if(p.second == max_freq) ans += p.second;
        }
        return ans;
    }
};