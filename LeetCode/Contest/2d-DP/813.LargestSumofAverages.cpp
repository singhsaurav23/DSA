//memoization->use of prev to find average
class Solution {
public:
    double memo(int i, vector<int>& p, int k, int prev, vector<vector<double>>& dp) {
        if (k == 0) {

            if (prev != -1)
                return (double)((double)(p[p.size() - 1] - p[prev]) / (double)(p.size() - 1 - prev));
            else return (double)((double)p[p.size() - 1] / (double)(p.size()));

        }
        if (dp[i][k] != -1.0) return dp[i][k];
        if (i == p.size()) return 0.0;
        int sum = 0;
        double ma = 0.0;
        for (int j = i; j < p.size(); j++) {
            if (k > 0) {
                if (prev == -1) {
                    ma = max(ma, (double)((double)p[j] / (double)(j + 1)) +
                        memo(j + 1, p, k - 1, j, dp));
                }
                else {
                    ma = max(ma, (double)((double)(p[j] - p[prev]) / (double)(j - prev)) +
                        memo(j + 1, p, k - 1, j, dp));
                }
                // cout<<ma<<" ";
            }
            else break;
        }
        return dp[i][k] = ma;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<int> p(nums.size());
        p[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) { p[i] = nums[i]; p[i] += p[i - 1]; }
        vector<vector<double>> dp(nums.size() + 1, vector<double>(k + 1, -1.0));
        return memo(0, p, k - 1, -1, dp);
    }
};

//bottom up->state i and k use prev to find same logic

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int i, j, n = nums.size(), m;
        vector<int> p(nums.size());
        p[0] = nums[0];
        for (i = 1; i < n; i++) { p[i] = nums[i]; p[i] += p[i - 1]; }
        vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0.0));
        for (i = 0; i < n; i++) dp[i][1] = ((double)p[i] / (double)(i + 1));

        for (m = 2; m <= k; m++) {
            for (i = 1; i < n; i++) {
                for (int prev = i - 1; prev >= 0; prev--) {
                    //if((i-prev)<m) continue;
                    dp[i][m] = max(dp[i][m], dp[prev][m - 1] + (double)((double)(p[i] - p[prev]) / (double)(i - prev)));
                }
            }
        }
        return dp[n - 1][k];
    }
};

//optimized tabulation

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int i, j, n = nums.size(), m;
        vector<int> p(nums.size());
        p[0] = nums[0];
        for (i = 1; i < n; i++) { p[i] = nums[i]; p[i] += p[i - 1]; }
        vector<double> pre(n + 1, 0.0), cur(n + 1, 0.0);
        for (i = 0; i < n; i++) pre[i] = ((double)p[i] / (double)(i + 1));

        for (m = 2; m <= k; m++) {
            for (i = 1; i < n; i++) {
                for (int prev = i - 1; prev >= 0; prev--) {
                    cur[i] = max(cur[i], pre[prev] + (double)((double)(p[i] - p[prev]) / (double)(i - prev)));
                }
            }
            pre = cur;
        }
        return pre[n - 1];
    }
};