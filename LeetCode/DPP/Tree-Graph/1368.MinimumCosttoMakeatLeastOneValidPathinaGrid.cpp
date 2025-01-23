// given grid you can change one cell direction with cost 1-> find minimu  cost in a grid->may not be shortest path but minimum cost to reach corner cell..
// always minimum cost->dijkstra algo->minimum pe dijkstra  start from 0,0 to every vcell distance

//TC->O(N*M*LOG(N*M))
#define ll long long
class Solution {

    struct cell {
        ll x, y, z;
        cell(ll x, ll y, ll z) :x(x), y(y), z(z) {}
        bool operator<(const cell& other) const {
            return x >= other.x;
        }
    };

public:
    ll dx[5] = { 0,0,0,1,-1 };
    ll dy[5] = { 0,1,-1,0,0 };
    long long minCost(vector<vector<int>>& grid) {
        ll n = grid.size(), m = grid[0].size();
        priority_queue<cell> pq;
        pq.push(cell(0, 0, 0));
        vector<vector<ll>> dis(n, vector<ll>(m, LONG_MAX));
        dis[0][0] = 0;
        while (!pq.empty()) {
            cell c = pq.top();
            pq.pop();
            ll di = c.x;
            ll p = c.y;
            ll q = c.z;
            for (ll ii = 1; ii <= 4; ii++) {
                ll pp = p + dx[ii];
                ll qq = q + dy[ii];
                if (pp < 0 || qq < 0 || pp >= n || qq >= m) continue;
                ll w = 1;
                if (p + dx[grid[p][q]] == pp && q + dy[grid[p][q]] == qq) w = 0;
                if (dis[pp][qq] > (di + w)) {
                    dis[pp][qq] = di + w;
                    pq.push(cell(di + w, pp, qq));
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};


//TC-O(N*M) ->0-1 BFS sinc weight is only 0 or 1,, use dequeu put 0 at first 1 at back in same code logn factor will go

class Solution {
public:
    // Direction vectors: right, left, down, up (matching grid values 1, 2, 3,
    // 4)
    vector<vector<int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    int minCost(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size();

        // Track minimum cost to reach each cell
        vector<vector<int>> minCost(numRows, vector<int>(numCols, INT_MAX));

        // Use deque for 0-1 BFS - add zero cost moves to front, cost=1 to back
        deque<pair<int, int>> deque;
        deque.push_front({ 0, 0 });
        minCost[0][0] = 0;

        while (!deque.empty()) {
            auto [row, col] = deque.front();
            deque.pop_front();

            // Try all four directions
            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];
                int cost = (grid[row][col] != (dir + 1)) ? 1 : 0;

                // If position is valid and we found a better path
                if (isValid(newRow, newCol, numRows, numCols) &&
                    minCost[row][col] + cost < minCost[newRow][newCol]) {
                    minCost[newRow][newCol] = minCost[row][col] + cost;

                    // Add to back if cost=1, front if cost=0
                    if (cost == 1) {
                        deque.push_back({ newRow, newCol });
                    }
                    else {
                        deque.push_front({ newRow, newCol });
                    }
                }
            }
        }

        return minCost[numRows - 1][numCols - 1];
    }

private:
    // Check if coordinates are within grid bounds
    bool isValid(int row, int col, int numRows, int numCols) {
        return row >= 0 && row < numRows && col >= 0 && col < numCols;
    }
};