/*
* Intutiotion - start taking from 0 to n-1 and 1 to n so that alternate are not taken and only n/3 slices
Mmemoixation 
*/

class Solution {
public:
    int slice(int i, int l, int c, vector<int>& slices, vector<vector<int>>& dp) {
        if (c == 0) return 0;
        if (i >= slices.size() || i >= l) return INT_MIN;
        if (dp[i][c] != -1) return dp[i][c];
        long p = 0, np = 0;
        // cout<<i<<" ";
        p = slices[i] + slice(i + 2, l, c - 1, slices, dp);
        np = slice(i + 1, l, c, slices, dp);
        return dp[i][c] = max(p, np);
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp(n + 1, vector<int>(n / 3 + 1, -1));
        int x = slice(0, n - 1, n / 3, slices, dp);
        vector<vector<int>> dpp(n + 1, vector<int>(n / 3 + 1, -1));
        int y = slice(1, n, n / 3, slices, dpp);
        return max(x, y);
    }
};

//tabulation

class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int m = n / 3, i, j;

        auto run = [&](int l, int r) {
            vector<vector<int>> dp(n + 2, vector<int>(m + 1, 0));

            for (i = r - 1; i >= l; i--) {
                for (j = 1; j <= m; j++) {
                    int t = 0, nt = 0;
                    t = slices[i] + dp[i + 2][j - 1];
                    nt = dp[i + 1][j];
                    dp[i][j] = max(t, nt);
                }
            }
            return dp[l][m];
        };

        int case1 = run(0, n - 1);
        int case2 = run(1, n);
        return max(case1, case2);

    }
};

//space optimized tabulation
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int m = n / 3;

        auto run = [&](int start, int end) {
            // only three rows of length m+1
            vector<int> next2(m + 1, 0),
                next1(m + 1, 0),
                curr(m + 1, 0);

            for (int i = end; i >= start; --i) {
                // c = 0 always yields 0, so we skip it
                for (int c = 1; c <= m; ++c) {
                    int pick = slices[i] + next2[c - 1];
                    int skip = next1[c];
                    curr[c] = max(pick, skip);
                }
                // roll buffers: next2 ← next1, next1 ← curr
                next2.swap(next1);
                next1.swap(curr);
                // now 'curr' holds old next2; its contents
                // will be fully overwritten on the next i
            }
            // after the final iteration at i == start,
            // the answer is in next1[m]
            return next1[m];
        };

        // Case A: allow slice[0] → forbid slice[n-1]
        int caseA = run(0, n - 2);
        // Case B: forbid slice[0] → allow slice[n-1]
        int caseB = run(1, n - 1);

        return max(caseA, caseB);
    }
};