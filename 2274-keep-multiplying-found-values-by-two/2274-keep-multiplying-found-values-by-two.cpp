class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> st;
        for(int num : nums){
            st.insert(num);
        }

        for(int num : nums){
            if(st.find(original) != st.end()){
                original *= 2;
            }
            else break;
        }
        return original;
    }
};