class MinStack {
    int topp = -1;
    int size = 0;
    int stack[10000];
public:
    MinStack() {
        
    }
    
    void push(int val) {
        topp++;
        stack[topp] = val;
        size++;
    }
    
    void pop() {
        if(topp == -1) return;
        topp--;
        size--;
    }
    
    int top() {
        return stack[topp];
    }
    
    int getMin() {
        int min = INT_MAX;
        for(int i = 0; i < size; i++){
            if(stack[i] < min) min = stack[i];
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */