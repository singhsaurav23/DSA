class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int c = 0, i, j, n = grid.size(), m = grid[0].size();
        vector<int> row(n, 0), col(m, 0);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j]) { row[i]++; col[j]++; }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j] && (row[i] >= 2 || col[j] >= 2)) c++;
            }
        }
        return c;
    }
};


//avoid unnecessary work again
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0, i, j, n = grid.size(), m = grid[0].size();
        vector<int> col(m, 0), last(n, -1);
        for (i = 0; i < n; i++) {
            int c = 0;
            for (j = 0; j < m; j++) {
                if (grid[i][j]) { c++; col[j]++; last[i] = j; }
            }
            if (c != 1) {
                ans += c;
                last[i] = -1;
            }
        }
        for (i = 0; i < n; i++) {
            ans += last[i] != -1 && col[last[i]] > 1;
        }
        return ans;
    }
};