class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans = 0;
        int n = moves.size();
        int left = 0;
        int right = 0;

        for(int move: moves){
            if(move == 'L') left++;
            else if(move == 'R') right++;
            else ans++;
        }
        return abs(right - left) + ans;
    }
};