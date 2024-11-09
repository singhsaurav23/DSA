// there are n node and m monuments which you have to place . you can place m monuments ar root and m-1 monuments at children of root,
// condition is find number of ways you can place m monuments such that no adjacent nodes have same monument and parent of adjacent node should also have a dffernet monument type.
// n=3, m=4 [1 1]->[2,3] 1 parent of 2 and 3 so answer is 24->4*3*2;
// question link->https://leetcode.com/discuss/interview-question/5110870/DE-Shaw-OA

#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

int main() {
    ll n, m, i;
    cin >> m >> n;
    vector<ll> a(n - 1), b(n - 1);
    for (i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    vector<ll> adj[n + 1];
    for (i = 0; i < n - 1; i++) {
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    ll total = m;
    vector<ll> mpc(m, 1);
    ll t = m - 2;
    for (i = 1; i <= (m - 2); i++) {
        mpc[i] = t;
        t = (t % mod * (m - 2 - i) % mod) % mod;
    }

    t = m - 1;
    for (i = 1; i < adj[1].size(); i++) {
        t = (t % mod * (m - 1 - i) % mod) % mod;
    }

    total = (total % mod * t % mod) % mod;
    queue<ll> q;
    for (auto it : adj[1]) {
        q.push(it);
    }
    vector<bool> vis(n + 1, false);
    vis[1] = true;

    while (!q.empty()) {
        ll s = q.size();
        while (s--) {
            ll top = q.front();
            q.pop();
            vis[top] = true;
            ll size = adj[top].size() - 1;
            if (size != 0)
                total = (total % mod * mpc[size] % mod) % mod;
            for (auto it : adj[top]) {
                if (vis[it] == false) {
                    q.push(it);
                }
            }
        }
    }
    cout << total << endl;
    return 0;
}



long subproblem(int m, vector<vector<int>>& adj, int node, int parent, vector<int>& mpc, long& total) {
    const long mod = 1e9 + 7;
    int numChildren = adj[node].size();
    if (parent != -1) numChildren--;

    if (numChildren > m - 2) return -1;
    if (numChildren == 0) return 0;

    total *= mpc[numChildren];
    total %= mod;

    for (int child : adj[node]) {
        if (child == parent) continue;
        int ret = subproblem(m, adj, child, node, mpc, total);
        if (ret == -1) return -1;
    }
    return 0;
}

int buildingMonuments(int m, int n, vector<int>& from, vector<int>& to) {
    const long mod = 1e9 + 7;

    // calculating (m-2) p c
    vector<int> mpc(m + 1, 0);
    long mprod = m - 2;
    for (int ii = 1; ii <= m - 2; ++ii) {
        mpc[ii] = mprod;
        mprod *= (m - 2 - ii);
        mprod %= mod;
    }

    // create adj list
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int ii = 0; ii < from.size(); ++ii) {
        adj[from[ii]].push_back(to[ii]);
        adj[to[ii]].push_back(from[ii]);
    }

    // pick 1st node as a root and traverse down.
    int root = 1;
    long numPossible = m; // m way to set root
    int numRootChildren = adj[root].size();
    if (numRootChildren > m - 1) return 0; //not possible

    // add (m-1) p numRootChildren
    long mproot = m - 1;
    for (int ii = 1; ii < numRootChildren; ++ii) {
        mproot *= (m - 1 - ii);
        mproot %= mod;
    }
    numPossible *= mproot;
    numPossible %= mod;

    for (int child : adj[root]) {
        int ret = subproblem(m, adj, child, root, mpc, numPossible);
        if (ret == -1) return 0;
    }
    return numPossible;
}