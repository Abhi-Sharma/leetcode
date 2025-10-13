class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();
        for(int i = 0; i < n; i++){
            pq.push(stones[i]);
        }

        while(!pq.empty()){
            if(pq.size() == 1) return pq.top();
            int max1 = pq.top();
            pq.pop();
            int max2 = pq.top();
            pq.pop();
            int diff = max1 - max2;
            pq.push(diff);
        }
        return 0;
    }
};