class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        long long res = 1;
        for(int i = 0; i < rowIndex; i++){
            res = res * (rowIndex - i);
            res = res / (i + 1);
            ans.push_back(res);
        }
        return ans;
    }
};