class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.length()-1;
        while (left <= right && s[left] == ' ') left++;
        while (right >= 0 && s[right] == ' ') right--;
        string temp = "";
        string ans = "";
        while(left <= right){
            char ch = s[left];
            if(ch != ' ') temp += ch;
            else {
                if(temp != ""){
                    if(ans != "") ans = temp + ' ' + ans;
                    else ans = temp;
                    temp = "";
                }
                while (left <= right && s[left] == ' ') left++;
                continue;
            }
            left++;
        }
        if(temp != ""){
            if(ans != "") ans = temp + ' ' + ans;
            else ans = temp;
        }
        return ans;
    }
};