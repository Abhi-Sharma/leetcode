class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        int n = queries.size();
        int m = dictionary.size();

        for(int i = 0; i < n; i++){
            string temp = queries[i];
            int len = temp.length();

            for(int j = 0; j < m; j++){
                int count = 0;
                string temp1 = dictionary[j];
                int len1 = temp1.length();
                int k = 0;
                while(k < len1){
                    if(temp[k] != temp1[k]) count++;
                    k++;
                }
                if(count <= 2) {
                    ans.push_back(temp);
                    break;
                }
            }
        }
        return ans;
    }
};