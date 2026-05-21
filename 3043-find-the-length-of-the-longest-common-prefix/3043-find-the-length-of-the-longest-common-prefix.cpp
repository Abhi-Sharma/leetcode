class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> s;

        for(int num : arr1){
            string ans = to_string(num);

            string prefix = "";
            for(char ch : ans){
                prefix += ch;
                s.insert(prefix);
            }
        }
        int res = 0;
        for(int num : arr2){
            string ans = to_string(num);

            string prefix = "";
            for(char ch : ans){
                prefix += ch;
                if(s.count(prefix)){
                    res = max(res, (int) prefix.size());
                }
            }
        }
        return res;
    }
};