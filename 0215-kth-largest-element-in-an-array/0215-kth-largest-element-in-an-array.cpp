class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }
        int limit = k - 1;
        while(limit > 0){
            pq.pop();
            limit--;
        }
        return pq.top();
    }
};