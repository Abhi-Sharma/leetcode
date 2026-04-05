class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();

        int r = 0;
        int c = 0;
        for(int i = 0; i < n; i++){
            if(moves[i] == 'U') r -= 1;
            else if(moves[i] == 'D') r += 1;
            else if(moves[i] == 'L') c -= 1;
            else c += 1;
        }

        return (r == 0 && c == 0);
    }
};