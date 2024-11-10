//https://leetcode.com/discuss/interview-question/5084258/DE-SHAW-OA-or-28-APR-2024-or-SMT-or-SOFTWARE-DEVELOPER-(BACKEND)-or/2374402
// see how beautifully bits can be used to define a path has odd even numbers /characters
void dfs(int node, int parent, int mask, vector<char>& A, vector<vector<int>>& adj, vector<int>& ans, map<int, int>& mp) {

    int cnt = 0;
    char ch = A[node];
    int req_mask = (1 << (ch - 'a')) ^ mask;

    cnt += mp.count(req_mask) ? mp[req_mask] : 0;
    for (int i = 0; i < 26; i++) {
        int another_possible_mask = req_mask ^ (1 << i);
        cnt += mp.count(another_possible_mask) ? mp[another_possible_mask] : 0;
    }
    ans[node] = cnt;

    mp[req_mask]++;
    for (auto x : adj[node]) {
        if (x != parent) {
            dfs(x, node, req_mask, A, adj, ans, mp);
        }
    }
    if (--mp[req_mask] == 0) mp.erase(req_mask);
}

vector<int> solution(int tree_nodes, vector<char>& A, vector<int>& tree_from, vector<int>& tree_to, vector<int>& q) {
    vector<vector<int>> adj(tree_nodes);
    map<int, int> mp;
    vector<int> ans(tree_nodes);

    for (int i = 0; i < tree_from.size(); i++) {
        adj[tree_from[i]].push_back(tree_to[i]);
        adj[tree_to[i]].push_back(tree_from[i]);
    }

    mp[0] = 1;
    dfs(0, -1, 0, A, adj, ans, mp);

    vector<int> res;
    for (auto x : q) res.push_back(ans[x]);
    return res;
}
int main() {
    int tree_nodes;
    cin >> tree_nodes;

    vector<char> A(tree_nodes);
    for (auto& x : A) cin >> x;

    vector<int> tree_from(tree_nodes - 1), tree_to(tree_nodes - 1);
    for (auto& x : tree_from) cin >> x;
    for (auto& x : tree_to) cin >> x;

    int m;
    cin >> m;
    vector<int> q(m);
    for (auto& x : q)
        cin >> x;

    vector<int> res = solution(tree_nodes, A, tree_from, tree_to, q);
    for (auto& x : res) cout << x << " ";
}