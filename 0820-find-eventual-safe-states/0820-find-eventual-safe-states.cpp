class Solution {
    private:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph, vector<int>& check){
        vis[node] = 1;
        check[node] = 0;

        for(auto it : graph[node]){
            if(vis[it] == 0){
                if(dfs(it,vis,graph,check) == true) return true;
            }
            else if(vis[it] == 1) return true;
        }

        vis[node] = 2;
        check[node] = 1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> check(V,0);
        vector<int> safeNodes;

        for(int i = 0; i < V; i++){
            if(vis[i] == 0)
            dfs(i,vis,graph,check);
        }

        for(int i = 0; i < V; i++){
            if(check[i] == 1) safeNodes.push_back(i);
        }

        return safeNodes;
        
    }
};