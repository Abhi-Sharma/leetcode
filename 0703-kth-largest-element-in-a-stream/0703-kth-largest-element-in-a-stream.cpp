class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minheap;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int num : nums){
            minheap.push(num);

            if(minheap.size() > k){
                minheap.pop();
            }
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size() > size) minheap.pop();

        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */