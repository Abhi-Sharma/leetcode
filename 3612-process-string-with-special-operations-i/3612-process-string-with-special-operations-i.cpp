class Solution {
public:
void reverseS(string& res){
    int left = 0;
    int right = res.size() - 1;

    while(left < right){
        swap(res[left],res[right]);
        left++;
        right--;
    }
}
    string processStr(string s) {
        string result = "";
        int n = s.size();


        for(int i = 0; i < n; i++){
            if(s[i] == '#') result += result;
            else if(s[i] == '%') reverseS(result);
            else if(s[i] == '*'){
                if(!result.empty()) result.pop_back(); 
            } 
            else result += s[i];
        }
        return result;
    }
};