class Solution {
    vector<int> getRow(int rowIndex) {
         long long anss = 1;
        vector<int> ans;
        ans.push_back(1);
        for(int i = 1; i < rowIndex; i++){
            anss = anss * (rowIndex - i);
            anss = anss / i;
            ans.push_back(anss);
        }
        return ans;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++){
            ans.push_back(getRow(i));
        }
        return ans;
    }
};