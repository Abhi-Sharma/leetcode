class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> mpp;

        for(int i = 0; i < n; i++){
            mpp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0] = 1;
        int steps = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                int ind = q.front();
                q.pop();

                if(ind == n-1) return steps;
                int right = ind + 1;
                int left = ind - 1;
                if(right < n && !vis[right]){
                    q.push(right);
                    vis[right] = 1;
                }
                if(left >= 0 && !vis[left]){
                    q.push(left);
                    vis[left] = 1;
                }

                for(auto idx : mpp[arr[ind]]){
                    if(!vis[idx]){
                        q.push(idx);
                        vis[idx] = 1;
                    }
                }
                mpp[arr[ind]].clear();
            }
            steps++;
        }
        return 0;
    }
};