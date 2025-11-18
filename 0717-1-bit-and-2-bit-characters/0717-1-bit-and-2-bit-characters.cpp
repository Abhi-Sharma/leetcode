class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        int j = 0;
        while(i < n){
            if(bits[i] == 1) {
                j = i;
                i += 2;
            }
            else{
                j = i; 
                i += 1;
            }
        }
        if(bits[j] == 1) return false;
        return true;
    }
};