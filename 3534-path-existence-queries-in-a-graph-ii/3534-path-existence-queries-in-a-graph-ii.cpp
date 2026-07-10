class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> pos(n);

        for (int i = 0; i < n; i++)
            pos[arr[i].second] = i;

     
        vector<int> nxt(n);

        int j = 0;

        for (int i = 0; i < n; i++) {

            while (j + 1 < n &&
                   arr[j + 1].first - arr[i].first <= maxDiff)
                j++;

            nxt[i] = j;
        }

        int LOG = 20;

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for (int k = 1; k < LOG; k++) {

            for (int i = 0; i < n; i++) {

                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {

            int u = pos[queries[i][0]];
            int v = pos[queries[i][1]];

            if (u > v)
                swap(u, v);

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int cur = u;
            int jumps = 0;

            for (int k = LOG - 1; k >= 0; k--) {

                if (up[k][cur] < v) {

                    cur = up[k][cur];
                    jumps += (1 << k);
                }
            }

            if (nxt[cur] < v)
                ans.push_back(-1);
            else
                ans.push_back(jumps + 1);
        }

        return ans;
    }
};