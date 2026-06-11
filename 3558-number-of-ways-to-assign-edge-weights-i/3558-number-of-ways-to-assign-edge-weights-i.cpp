class Solution {
public:
int maxDepth = 0;
void dfs(int node, int parent, int depth, vector<vector<int>>& adj){
    maxDepth = max(maxDepth,depth);

    for(auto nei : adj[node]){
        if(nei == parent) continue;
        dfs(nei,node,depth+1,adj);
    }
}

long long modPow(long long a, long long b){
    long long res = 1;
    long long MOD = 1e9 + 7;

    while(b){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for(auto &e: edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1,0,0,adj);

        int res = modPow(2,maxDepth-1);
        return res;
    }
};