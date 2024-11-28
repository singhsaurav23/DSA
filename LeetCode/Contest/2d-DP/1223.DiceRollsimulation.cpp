class Solution {
public:
    long mod = 1e9 + 7;
    int memo(int i, int ele, int times, int n, vector<int>& rollMax, vector<vector<vector<int>>>& dp) {
        if (i == n) return 1;
        if (dp[i][ele][times] != -1) return dp[i][ele][times];
        int cnt = 0;
        for (int j = 1; j <= 6; j++) {
            if (j == ele && (times + 1) <= rollMax[j - 1])
                cnt = (cnt % mod + memo(i + 1, j, times + 1, n, rollMax, dp) % mod) % mod;
            // pehli baar
            if (j != ele)
                cnt = (cnt % mod + memo(i + 1, j, 1, n, rollMax, dp) % mod) % mod;
        }
        return dp[i][ele][times] = cnt;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        int ma = 0;
        for (int i = 0; i < rollMax.size(); i++) ma = max(ma, rollMax[i]);
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(7, vector<int>(ma + 1, -1)));
        return memo(0, 0, 0, n, rollMax, dp);
    }
};

