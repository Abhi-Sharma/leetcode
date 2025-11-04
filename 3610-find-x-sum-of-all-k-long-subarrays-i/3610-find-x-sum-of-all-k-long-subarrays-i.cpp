class Solution {
    int computeXsum(unordered_map<int,int>& freq, int x){
        vector<pair<int,int>> v(freq.begin(),freq.end());

        sort(v.begin(),v.end(),[](pair<int,int>& a, pair<int,int>& b){
            if(a.second == b.second) return a.first > b.first;
            return a.second > b.second;
        });

        int sum = 0;
        int count = 0;
        for(auto p : v){
            if(count == x) break;
            sum += p.first * p.second;
            count++;
        }
        return sum;
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        unordered_map<int,int> freq;
        int n = nums.size();

        for(int i = 0; i < k; i++){
            freq[nums[i]]++;
        }
        ans.push_back(computeXsum(freq,x));

        for(int i = k; i < n; i++){
            int removeNum = nums[i-k];
            int addNum = nums[i];

            freq[removeNum]--;
            if(freq[removeNum] == 0) freq.erase(removeNum);

            freq[addNum]++;

            ans.push_back(computeXsum(freq,x));
        }
        return ans;
    }
};