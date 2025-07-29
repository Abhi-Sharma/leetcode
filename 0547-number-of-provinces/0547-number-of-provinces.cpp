class Solution {
    void bfs(int node, vector<vector<int>> adjls, vector<int>& vis){
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int n = q.front();
            q.pop();
            for(auto it : adjls[n]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjls(V);
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        vector<int> vis(V,0);
        int count = 0;
        for(int i = 0; i < V; i++){
            if(vis[i] == 0){
                count++;
                bfs(i,adjls,vis);
            }
        }

        return count;
    }
};