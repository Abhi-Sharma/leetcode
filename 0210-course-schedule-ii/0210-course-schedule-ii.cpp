class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
      for (auto p : prerequisites) {
            int a = p[0]; 
            int b = p[1]; 
            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> courses;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            courses.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
      if(courses.size() == numCourses)  return courses;
      return {};
    }
};