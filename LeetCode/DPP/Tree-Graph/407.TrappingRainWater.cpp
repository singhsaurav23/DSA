//boundary cells minimum will b eth maximum contained height for boundaries
// for each cell check minimum bondary 4 directions.
// start from bondary cells with min heighto to bfs and mark all nodes and find answer for that sepcific node

class Solution {
    struct Cell {
        int x;
        int y;
        int z;
        Cell(int x, int y, int z) :x(x), y(y), z(z) {}
        bool operator<(const Cell& other) const {
            return x >= other.x;
        }

    };
public:
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    bool isvalid(int i, int j, vector<vector<int>>& h) {
        if (i <= 0 || j <= 0 || i >= h.size() - 1 || j >= h[0].size() - 1 || h[i][j] == -1) return false;
        return true;
    }
    int trapRainWater(vector<vector<int>>& h) {
        int ans = 0, i, j, n = h.size(), m = h[0].size();
        i = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<Cell> pq;
        // Push boundary cells into priority queue
        for (j = 1; j < m - 1; j++) {
            pq.push(Cell(h[0][j], 0, j));
            pq.push(Cell(h[n - 1][j], n - 1, j));
            vis[0][j] = vis[n - 1][j] = -1;
        }
        for (i = 1; i < n - 1; i++) {
            pq.push(Cell(h[i][0], i, 0));
            pq.push(Cell(h[i][m - 1], i, m - 1));
            vis[i][0] = vis[i][m - 1] = -1;
        }

        while (!pq.empty()) {
            Cell c = pq.top();
            pq.pop();

            for (i = 0; i < 4; i++) {
                int xx = dx[i] + c.y;
                int yy = dy[i] + c.z;
                if (isvalid(xx, yy, vis)) {
                    if (c.x > h[xx][yy]) {
                        //cout<<xx<<" "<<yy<<" "<<c.x<<" "<<h[xx][yy]<<endl; 
                        ans += (c.x - h[xx][yy]);
                        pq.push(Cell(c.x, xx, yy));

                    }
                    else {
                        pq.push(Cell(h[xx][yy], xx, yy));
                    }
                    vis[xx][yy] = -1;
                }
            }
        }
        return ans;
    }
};
/*
3 3 3 3
3 2 2 3
3 3 2 3*/