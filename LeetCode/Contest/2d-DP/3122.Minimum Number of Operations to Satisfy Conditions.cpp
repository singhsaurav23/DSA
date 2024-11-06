
// consider prev element and curr element to be taken from 0-10 and for each column and number of ways=n-freq[curr]
//TC-O(N*M+M*100) SC-O(M*10+M*10+10)
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(10, 1e7)), cnt(m, vector<int>(10, 0));
        int i, curr, prev;
        for (i = 0; i < m; i++) {
            for (curr = 0; curr < n; curr++) {
                cnt[i][grid[curr][i]]++;
            }
        }
        for (i = 0; i < m; i++) {
            for (curr = 0; curr < 10; curr++) {
                for (prev = 0; prev < 10; prev++) {
                    if (curr != prev) {
                        if (i == 0) dp[i][curr] = min(dp[i][curr], n - cnt[i][curr]);
                        else
                            dp[i][curr] = min(dp[i][curr], dp[i - 1][prev] + n - cnt[i][curr]);
                    }
                }
            }
        }
        int mi = 1e9;
        for (i = 0; i < 10; i++) {
            mi = min(mi, dp[m - 1][i]);
        }
        return mi;
    }
};

//space optimized O(10+M*10)
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> cnt(m, vector<int>(10, 0));
        vector<int> pre(10, 0);
        int i, curr, prev;
        for (i = 0; i < m; i++) {
            for (curr = 0; curr < n; curr++) {
                cnt[i][grid[curr][i]]++;
            }
        }
        for (i = 0; i < m; i++) {
            vector<int> cur(10, 1e9);
            for (curr = 0; curr < 10; curr++) {
                for (prev = 0; prev < 10; prev++) {
                    if (curr != prev) {
                        cur[curr] = min(cur[curr], pre[prev] + n - cnt[i][curr]);
                    }
                }
            }
            pre = cur;
        }
        int mi = 1e9;
        for (i = 0; i < 10; i++) {
            mi = min(mi, pre[i]);
        }
        return mi;
    }
};