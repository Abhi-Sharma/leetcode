class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalgas = 0;
        int totalcost = 0;

        for(int i = 0; i < n; i++){
            totalgas += gas[i];
            totalcost += cost[i];
        }

        if(totalgas < totalcost) return -1;

        int tank = 0;
        int start = 0;

        for(int i = 0; i < n; i++){
            tank += gas[i] - cost[i];

            if(tank < 0){
                start = i + 1;
                tank = 0;
            }
        }
        return start;
    }
};