// Biweekly contest 142 Q2. Find Subtree Sizes After Changes
// simulatanously find closest parent and then find subtreee size using dfs 

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& pa, string s) {
        int n = pa.size(), i;
        vector<vector<int>> children(n);
        vector<int> par(n, -1);
        for (i = 0; i < n; i++) {
            if (pa[i] == -1) continue;

            int curr = pa[i];
            while (curr != -1) {
                if (s[curr] == s[i]) {
                    par[i] = curr;
                    break;
                }
                curr = pa[curr];
            }
        }

        for (i = 0; i < n; i++) {
            if (par[i] != -1) pa[i] = par[i];
        }

        // Calculate subtree sizes bottom-up
        vector<int> ans(n, 1);


        // Build children array after compression
        for (int i = 0; i < n; i++) {
            if (pa[i] != -1) {
                children[pa[i]].push_back(i);
            }
        }

        // DFS to calculate subtree sizes
        function<int(int, int)> dfss = [&](int node, int p) -> int {
            int size = 0;
            for (int child : children[node]) {
                if (child != p) {
                    dfss(child, node);
                    size += ans[child];
                }
            }
            return ans[node] = 1 + size;
        };

        dfss(0, -1); // Start from root
        return ans;
    }
};