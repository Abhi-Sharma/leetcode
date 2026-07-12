class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr);
        sort(temp.begin(),temp.end());

        map<int,int> numTorank;
        int rank = 1;
        for(int i = 0; i < temp.size(); i++){
            if(i > 0 && temp[i] > temp[i-1]) rank++;
            numTorank[temp[i]] = rank;
        }

        for(int i = 0; i < arr.size(); i++){
            arr[i] = numTorank[arr[i]];
        }

        return arr;
    }
};