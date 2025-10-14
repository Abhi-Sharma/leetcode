class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }

        int cnt = 0;
        int longest = 0;
        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                cnt = 1;
                while(st.find(it + 1) != st.end()){
                    it += 1;
                    cnt++;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};