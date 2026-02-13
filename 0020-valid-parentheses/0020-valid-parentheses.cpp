class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else{
                if(st.empty() || s[i] == ')' && st.top() != '(' || s[i] == '}' && st.top() != '{' || s[i] == ']' && st.top() != '[') return false;
                st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }
};