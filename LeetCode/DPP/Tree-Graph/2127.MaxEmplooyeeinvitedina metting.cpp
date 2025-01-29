//find cycle length and ascyclic length with cycle =2 summation find max path using bfs

class Solution {
public:
    int bfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        queue<pair<int, int>> que; //{node, path length}
        que.push({ i, 0 });
        int maxDistance = 0;

        while (!que.empty()) {
            auto [currNode, dist] = que.front();
            que.pop();

            for (auto& ngbr : adj[currNode]) {
                if (!visited[ngbr]) {
                    visited[ngbr] = true;
                    que.push({ ngbr, dist + 1 });
                    maxDistance = max(maxDistance, dist + 1);
                }
            }
        }

        return maxDistance;
    }
    int maximumInvitations(vector<int>& fav) {
        int n = fav.size(), i;
        unordered_map<int, vector<int>> adj;
        for (i = 0; i < n; i++) {
            adj[fav[i]].push_back(i);
        }
        vector<int> vis(n, 0);
        int cycle = 0, acyclic_2Cyc = 0;
        for (i = 0; i < n; i++) {
            if (vis[i] == 0) {
                unordered_map<int, int> mp;
                int nc = 0, c = i;
                while (vis[c] == 0) {
                    vis[c] = 1;
                    mp[c] = nc;
                    int next = fav[c];
                    nc++;
                    if (mp.find(next) != mp.end()) {
                        int len = nc - mp[next];
                        cycle = max(cycle, len);
                        if (len == 2) {
                            vector<bool> v(n, false);
                            v[c] = true;
                            v[next] = true;
                            acyclic_2Cyc += (2 + bfs(c, adj, v) + bfs(next, adj, v));
                        }
                        break;
                    }
                    c = next;
                }
            }
        }


        return max(cycle, acyclic_2Cyc);
    }
};