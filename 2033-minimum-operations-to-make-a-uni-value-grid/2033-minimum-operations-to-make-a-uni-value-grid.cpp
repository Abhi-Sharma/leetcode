class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> ans;

        for(auto& row : grid){
            for(int num : row) ans.push_back(num);
        }

        int rem = ans[0] % x;
        for(int num : ans){
            if(num % x != rem) return -1;
        }

        sort(ans.begin(),ans.end());
        int n = ans.size();
        int median = ans[n/2];

        int operations = 0;
        for(int num : ans){
            operations += abs(num - median) / x;
        }

        return operations;
    }
};