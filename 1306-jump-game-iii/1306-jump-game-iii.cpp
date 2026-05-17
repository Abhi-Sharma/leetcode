class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);

        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while(!q.empty()){
            int ind = q.front();
            q.pop();

            if(arr[ind] == 0) return true;
            if(ind + arr[ind] < n && !vis[ind + arr[ind]]){
                vis[ind + arr[ind]] = 1;
                q.push(ind + arr[ind]);
            }
            if(ind - arr[ind] >= 0 && !vis[ind - arr[ind]]){
                vis[ind - arr[ind]] = 1;
                q.push(ind - arr[ind]);
            } 
        }
        return false;
    }
};