//memoization sort age wise and use previous index to take or nottake i

class Solution {
public:
    int knap(int i, vector<vector<int>>& vp, int prev, vector<vector<int>>& dp) {
        if (i == vp.size()) return 0;
        if (prev != -1 && dp[i][prev] != -1) return dp[i][prev];
        int t = 0, nt = 0;
        if (prev == -1) {
            t = vp[i][1] + knap(i + 1, vp, i, dp);
        }
        else {
            if (vp[prev][0] == vp[i][0] || vp[prev][1] <= vp[i][1]) {
                t = vp[i][1] + knap(i + 1, vp, (vp[prev][1] <= vp[i][1]) ? i : prev, dp);
            }
        }
        nt = knap(i + 1, vp, prev, dp);
        if (prev == -1)
            return max(t, nt);
        return dp[i][prev] = max(t, nt);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int i, n = scores.size();
        vector<vector<int>> vp(n, vector<int>(2));
        for (i = 0; i < n; i++) {
            vp[i][0] = ages[i];
            vp[i][1] = scores[i];
        }
        sort(vp.begin(), vp.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
            });
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return knap(0, vp, -1, dp);
    }
};

// tabulation - LIS
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int i, n = scores.size(), j;
        vector<vector<int>> vp(n, vector<int>(2));
        for (i = 0; i < n; i++) {
            vp[i][0] = ages[i];
            vp[i][1] = scores[i];
        }
        sort(vp.begin(), vp.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
            });
        vector<int> dp(n + 1, 0);
        dp[0] = vp[0][1];
        int ans = dp[0];
        for (i = 1; i < n; i++) {
            dp[i] = vp[i][1];
            for (j = 0; j < i; j++) {
                if (vp[j][0] == vp[i][0] || vp[j][1] <= vp[i][1]) {
                    dp[i] = max(dp[i], dp[j] + vp[i][1]);
                }

            }
            ans = max(ans, dp[i]);
        }
        return ans;

    }
};