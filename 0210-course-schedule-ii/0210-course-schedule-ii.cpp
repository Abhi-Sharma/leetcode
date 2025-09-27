class Solution {
    private:
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& adj,
     vector<int>& order){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(vis[it] == 0){
                if(dfs(it,vis,adj,order) == true) return true;
            }
            else if(vis[it] == 1) return true;
        }
        vis[node] = 2;
        order.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto &e : prerequisites)
        {
            int u = e[0], v = e[1];
            adj[v].push_back(u);
        }

        vector<int> vis(numCourses, 0), pathVis(numCourses, 0), order;
        for(int i = 0 ; i < numCourses; i++){
            if(vis[i] == 0){
                if(dfs(i,vis,adj,order)) return {};
            }
        }

        reverse(order.begin(),order.end());
        return order;
    }
};