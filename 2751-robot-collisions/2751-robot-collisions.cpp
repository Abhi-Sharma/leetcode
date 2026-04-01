class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> actual_index(n);
        for(int i = 0; i < n; i++){
            actual_index[i] = i;
        }
        auto lambda = [&](int& i, int& j){
            return positions[i] < positions[j];
        };
        sort(begin(actual_index),end(actual_index), lambda);

        
        stack<int> st;

        for(int& curr : actual_index){
            if(directions[curr] == 'R') st.push(curr);
            else{
                while(!st.empty() && healths[curr] > 0){
                    int top = st.top();
                    st.pop();
                    if(healths[top] > healths[curr]){
                        healths[top] -= 1;
                        healths[curr] = 0;
                        st.push(top);
                    }
                    else if(healths[top] < healths[curr]){
                        healths[curr] -= 1;
                        healths[top] = 0;
                    }
                    else{
                        healths[top] = 0;
                        healths[curr] = 0;
                    }
                }
            }
        }

        vector<int> result;
        for(int i = 0; i < n; i++){
            if(healths[i] > 0) result.push_back(healths[i]);
        }

        return result;
    }
};