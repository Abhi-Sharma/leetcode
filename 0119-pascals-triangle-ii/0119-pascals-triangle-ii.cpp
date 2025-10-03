class Solution {
public:
    vector<int> getRow(int rowIndex) {
         long long anss = 1;
        vector<int> ans;
        ans.push_back(1);
        for(int i = 1; i <= rowIndex; i++){
            anss = anss * (rowIndex - i + 1);
            anss = anss / i;
            ans.push_back(anss);
        }
        return ans;
    }
};