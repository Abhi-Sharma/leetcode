class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        vector<string> rows(numRows);

        if(numRows == 1) return s;
        int currentRow = 0;
        bool down = true;
        for(char ch : s){
            rows[currentRow] += ch;

            if(currentRow == 0) down = true;
            else if(currentRow == numRows - 1) down = false;


            if(down) currentRow++;
            else currentRow--;
        }
        string ans = "";
        for(string row : rows){
            ans += row;
        }
        return ans;
    }
};