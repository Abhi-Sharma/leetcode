class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for(int x : nums){
            int r = x % 3;
            if(r == 1 || r == 2) cnt += 1; 
        }
        return cnt;
    }
};
