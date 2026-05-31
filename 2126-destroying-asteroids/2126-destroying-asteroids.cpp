class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        int n = asteroids.size();
        long long currMass = mass;
        for(int i = 0; i < n; i++){
            if(currMass < asteroids[i]) return false;
            currMass += asteroids[i];
        }
        return true;
    }
};