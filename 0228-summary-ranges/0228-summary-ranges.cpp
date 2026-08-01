class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int i = 0;
        int n = nums.size();

        while(i < n){
            int start = nums[i];

            while(i + 1 < n && nums[i+1] == nums[i] + 1) i++;
            
            int end = nums[i];
            if(start == end) ans.push_back(to_string(start));
            else ans.push_back(to_string(start) + "->" + to_string(end));
            
            i++;
        }
        return ans;
    }
};