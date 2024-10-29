//3316. Find Maximum Removals From Source String

//Approach-1 Memoization Go from 0 to end of str as sequence matters to maintain subsequence
class Solution {
public:
    unordered_set<int> st;
    int rem(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i == s.size()) {
            if (j == p.size()) return 0;
            else return -1e7;
        }

        if (dp[i][j] != -1) return dp[i][j];
        int t = 0;
        t = rem(i + 1, j, s, p, dp);
        if (st.find(i) != st.end()) t = max(t, 1 + t);
        if (s[i] == p[j]) {
            t = max(t, rem(i + 1, j + 1, s, p, dp));
        }


        return dp[i][j] = t;
    }
    int maxRemovals(string s, string p, vector<int>& idx) {
        for (auto it : idx) st.insert(it);
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return rem(0, 0, s, p, dp);
    }
};

//Approach-2 Tabulation

class Solution {
public:
    int maxRemovals(string s, string p, vector<int>& idx) {
        int n = s.size(), m = p.size();

        // Create set for quick lookup of removable indices
        unordered_set<int> removable;
        for (int i : idx) {
            removable.insert(i);
        }

        // dp[i][j] represents max removals possible considering
        // s[0...i] and p[0...j]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e7));

        // Base case: empty strings
        dp[0][0] = 0;

        // Fill dp table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0) continue;

                if (i == 0) {
                    dp[i][j] = -1e7;
                    continue;
                }

                // Don't include current character
                dp[i][j] = dp[i - 1][j];
                if (removable.find(i - 1) != removable.end()) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
                }

                // Include current character if it matches
                if (j > 0 && s[i - 1] == p[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }

        // Find maximum valid value in last row
        int result = 0;
        for (int i = 0; i <= n; i++) {
            if (dp[i][m] >= 0) {
                result = max(result, dp[i][m]);
            }
        }

        return result;
    }
};