//bfd with greedily maintaing k at each cell which is max so that obstacle use remains and if visisted already

class Solution {
public:
    int dx[4] = { 0,1,-1,0 };
    int dy[4] = { 1,0,0,-1 };
    bool valid(int i, int j, vector<vector<int>>& grid, int z) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;
        if (grid[i][j] == 1 && z <= 0) return false;
        return true;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        if (grid[0][0] == 1) k--;
        if (k < 0) return -1;

        queue<vector<int>> q;
        q.push({ 0,0,k });
        int cnt = 0;
        vector<vector<int>> dis(grid.size(), vector<int>(grid[0].size(), -1));
        while (!q.empty()) {
            int xx = q.size();
            while (xx--) {
                vector<int> p = q.front();
                q.pop();
                int x = p[0], y = p[1];

                if (x == grid.size() - 1 && y == grid[0].size() - 1) {
                    return cnt;
                }

                for (int i = 0; i < 4; i++) {

                    if (valid(x + dx[i], y + dy[i], grid, p[2])) {
                        int kk = p[2];
                        if (grid[x + dx[i]][y + dy[i]] == 1) kk--;
                        if (dis[x + dx[i]][y + dy[i]] != -1 && dis[x + dx[i]][y + dy[i]] >= kk)
                            continue;
                        dis[x + dx[i]][y + dy[i]] = kk;
                        q.push({ x + dx[i],y + dy[i],kk });
                    }
                }

            }
            cnt++;
        }
        return -1;
    }
};