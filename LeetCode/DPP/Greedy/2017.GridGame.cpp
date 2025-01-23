//if you need to minimize 2nd attempt of another person doesn't mean you have pick maximum->dp
// in order to minimize other check all instances of going down for first person and then decide which is worst for other person.
// prefix sum

#define ll long long
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int i, j;
        vector<vector<ll>> dp(2, vector<ll>(n, 0));
        dp[0][0] = grid[0][0];
        dp[1][0] = grid[1][0];
        for (j = 0; j < 2; j++) {
            for (i = 1; i < n; i++) dp[j][i] = (dp[j][i - 1] + grid[j][i]);
        }

        ll mi = LONG_MAX;
        for (i = 0; i < n; i++) {
            ll ans = dp[0][n - 1] - dp[0][i];
            if (i != 0) {
                ans = max(ans, dp[1][i - 1]);
            }
            mi = min(mi, ans);
        }
        return mi;
    }
};

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum = accumulate(begin(grid[0]), end(grid[0]), 0LL),
            secondRowSum = 0;
        long long minimumSum = LONG_LONG_MAX;
        for (int turnIndex = 0; turnIndex < grid[0].size(); ++turnIndex) {
            firstRowSum -= grid[0][turnIndex];
            // Find the minimum maximum value out of firstRowSum and
            // secondRowSum.
            minimumSum = min(minimumSum, max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][turnIndex];
        }
        return minimumSum;
    }
};