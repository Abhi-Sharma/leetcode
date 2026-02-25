class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        int cnt = 1;
        for(int i = 1; i < n; i++){
            string current = "";
            cnt = 1;
            for(int j = 1; j < result.size(); j++){
                if(result[j] == result[j-1]){
                    cnt++;
                }
                else{
                    current += to_string(cnt) + result[j-1];
                    cnt = 1;
                }
            }
            current += to_string(cnt) + result.back();
            result = current;
        }
        return result;
    }
};