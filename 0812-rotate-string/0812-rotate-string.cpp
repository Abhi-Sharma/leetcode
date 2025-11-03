class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        string doubleS = s + s;
        return doubleS.find(goal) != string::npos;
    }
};