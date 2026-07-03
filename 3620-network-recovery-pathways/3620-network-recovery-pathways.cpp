class Solution {
public:
int n;
    bool check(int mid, vector<vector<int>>& edges, vector<bool>& online, long long k) {

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n, 0);

        
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(w < mid) continue;

          
            if(v != n-1 && !online[v]) continue;
            if(u != 0 && !online[u]) continue;

            adj[u].push_back({v, w});
            indegree[v]++;
        }

       
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(indegree[i]==0)
                q.push(i);
        }

        vector<int> topo;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(auto &it:adj[node]) {
                indegree[it.first]--;
                if(indegree[it.first]==0)
                    q.push(it.first);
            }
        }

        
        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        dist[0]=0;

        for(int u:topo){
            if(dist[u]==INF) continue;

            for(auto &it:adj[u]){
                int v=it.first;
                int w=it.second;

                dist[v]=min(dist[v],dist[u]+w);
            }
        }

        return dist[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
         n=online.size();

        int low=0;
        int high=0;

        for(auto &e:edges)
            high=max(high,e[2]);

        int ans=-1;

        while(low<=high){

            int mid=low+(high-low)/2;

            if(check(mid,edges,online,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans;
    }
};