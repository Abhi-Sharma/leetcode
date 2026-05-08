class Solution {
public:
bool isPrime(int x){
    if(x < 2) return false;

    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}
    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> bucket;

        for(int i = 0; i < n; i++){
            int x = nums[i];

            for(int p = 2; p * p <= x; p++){
                if(x % p == 0){
                    bucket[p].push_back(i);

                    while(x % p == 0) x /= p;
                }
            }
            if(x > 1) bucket[x].push_back(i);
        }

        vector<int> vis(n,0);
        queue<pair<int,int>> q;
        q.push({0,0});

        while(!q.empty()){
            int idx = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if(idx == n - 1) return dist;

            if(idx - 1 >= 0 && !vis[idx-1]){
                vis[idx-1] = 1;
                q.push({idx - 1, dist + 1});
            }
            if(idx + 1 < n && !vis[idx + 1]){
                vis[idx + 1] = 1;
                q.push({idx + 1, dist + 1});
            }

            int val = nums[idx];

            if(isPrime(val)){
                for(int nextIdx : bucket[val]){
                    if(!vis[nextIdx]){
                        vis[nextIdx] = 1;
                        q.push({nextIdx, dist + 1});
                    }
                }
                bucket[val].clear();
            }
        }
        return -1;
    }
};