class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);

        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int ind = q.front();
            vis[ind] = 1;
            q.pop();

            if(arr[ind] == 0) return true;
            if(ind + arr[ind] < n && !vis[ind + arr[ind]]) q.push(ind + arr[ind]);
            if(ind - arr[ind] >= 0 && !vis[ind - arr[ind]]) q.push(ind - arr[ind]); 
        }
        return false;
    }
};