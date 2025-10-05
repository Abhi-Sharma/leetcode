class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }


        int cntcity = n;
        int cityno = -1;
        for(int src = 0; src < n; src++){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }

       
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(src != j && dist[j] <= distanceThreshold) cnt++;
        }

        if(cnt <= cntcity){
            cntcity = cnt;
            cityno = src;
        }
        }
        return cityno;
    }
};