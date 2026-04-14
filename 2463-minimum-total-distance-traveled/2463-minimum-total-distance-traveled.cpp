class Solution {
public:
    vector<int> robot;
    vector<vector<int>> factory;
    long long dp[101][101];

    long long solve(int i, int j) {
        if (i == robot.size()) return 0;
        if (j == factory.size()) return 1e15;

        if (dp[i][j] != -1) return dp[i][j];

        long long ans = solve(i, j + 1);

        long long cost = 0;
        int pos = factory[j][0];
        int limit = factory[j][1];

        for (int k = 1; k <= limit && i + k - 1 < robot.size(); k++) {
            cost += abs(robot[i + k - 1] - pos);
            ans = min(ans, cost + solve(i + k, j + 1));
        }

        return dp[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& r, vector<vector<int>>& f) {
        robot = r;
        factory = f;

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        memset(dp, -1, sizeof(dp));

        return solve(0, 0);
    }
};