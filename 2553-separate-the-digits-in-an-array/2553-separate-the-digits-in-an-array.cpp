class Solution {
public:
void digitsSep(vector<int>& ans, string num){
    for(int i = 0; i < num.size(); i++){
        char ch = num[i];
        int nums = ch - '0';
        ans.push_back(nums);
    }
}
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            string num = to_string(nums[i]);
            digitsSep(ans,num);
        }
        return ans;
    }
};