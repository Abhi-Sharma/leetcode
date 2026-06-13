class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string res = "";
        for(int i = 0; i < n; i++){
            string ans = words[i];

            int size = ans.size();
            int sum = 0;
            for(int i = 0; i < size; i++){
                char ch = ans[i];
                sum += weights[ch - 'a'];
            }
            sum = sum % 26;
            res += 'z' - sum;
        }
        return res;
    }
};