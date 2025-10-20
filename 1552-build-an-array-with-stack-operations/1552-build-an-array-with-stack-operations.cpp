class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int top = 0;
        for(int i = 1; i <= n; i++){
            if(top == target.size()) break;
            ans.push_back("Push");
            if(i == target[top]){
                top++;
            }
            else ans.push_back("Pop");
        }
        return ans;
    }
};