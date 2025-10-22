class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int nse , pse = -1;
        int maxArea = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int ind = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxArea = max((heights[ind] * (nse - pse - 1)),maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int ind = st.top();
            st.pop();
            nse = n;
            pse = st.empty() ? -1 : st.top();
            maxArea = max((heights[ind] * (nse - pse - 1)),maxArea);
        }
        return maxArea;
    }
};