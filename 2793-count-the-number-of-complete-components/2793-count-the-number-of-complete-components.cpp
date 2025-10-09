class Solution {
    void dfs(int node, vector<int>& vis, vector<int>& nodes, 
    int& edgecount,vector<vector<int>>& adj){
        vis[node] = 1;
        nodes.push_back(node);
        edgecount += adj[node].size();
        for(auto it : adj[node]){
            if(!vis[it]) {
                dfs(it,vis,nodes,edgecount,adj);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vector<int> nodes;
                int edgecount = 0;
                dfs(i,vis,nodes,edgecount,adj);
                int k = nodes.size();
                int actual = edgecount / 2;
                if(actual == k * (k - 1)/2) cnt++;
            }
        }
        return cnt;
    }
};