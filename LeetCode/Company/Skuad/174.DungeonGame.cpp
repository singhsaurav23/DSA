// try maintianing level of initial value to survive at each cell, bottom up if >0 it will be 0 as , it will help to find minimum  negative it can go for upper cells. to finid minimum initial health.

class Solution {
public:
    int dun(int i, int j, vector<vector<int>>& dung, vector<vector<int>>& dp) {
        if (i == dung.size() - 1 && j == dung[0].size() - 1) {
            if (dung[i][j] < 0)
                return dung[i][j];
            else return 0;
        }

        if (i >= dung.size() || j >= dung[0].size()) return -9999;
        if (dp[i][j] != -99999) return dp[i][j];
        int x = dung[i][j] + dun(i + 1, j, dung, dp);
        int y = dung[i][j] + dun(i, j + 1, dung, dp);
        int z = max(x, y);
        if (z < 0) {
            dp[i][j] = z;
            return dp[i][j];
        }
        return 0;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -99999));
        int z = dun(0, 0, dungeon, dp);
        return abs(z) + 1;
        return 1;
    }
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& v) {
        int i, j, n = v.size(), m = v[0].size(), ans = INT_MAX;
        for (i = n - 1; i >= 0; i--) {
            for (j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) {
                    v[i][j] = min(0, v[i][j]);
                }
                else if (i == n - 1) {
                    v[i][j] = min(0, v[i][j + 1] + v[i][j]);
                }
                else if (j == m - 1) {
                    v[i][j] = min(0, v[i + 1][j] + v[i][j]);
                }
                else {
                    v[i][j] = min(0, v[i][j] + max(v[i + 1][j], v[i][j + 1]));
                }
            }
        }
        return abs(v[0][0]) + 1;
    }

};