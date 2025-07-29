//color graph itertaing both parent and childs
// have all red colors one side and ocunt of blue to map edges

#include <bits/stdc++.h>
using namespace std;
#define ll long long


void dfs(ll root, vector<ll>& vis, vector<ll>* adj, vector<ll>& red, ll& bl, ll c, vector<ll>* par) {
    vis[root] = 1;

    if (c == 0) red.push_back(root);
    else bl++;

    for (auto it : adj[root]) {
        if (vis[it] == 0)
            dfs(it, vis, adj, red, bl, abs(c - 1), par);
    }
    for (auto it : par[root]) {
        if (vis[it] == 0) dfs(it, vis, adj, red, bl, abs(c - 1), par);
    }
}

int main() {
    ll n, i;
    cin >> n;
    unordered_map<ll, ll> mp;
    vector<ll> vis(n + 1, 0);
    ll bl = 0;
    vector<ll> adj[n + 1], par[n + 1];
    for (i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        mp[u]++;
        mp[v]++;
        par[v].push_back(u);
    }

    vector<ll> red;
    dfs(1, vis, adj, red, bl, 0, par);

    ll ans = 0;
    for (i = 0; i < red.size(); i++) {
        ans += (bl - mp[red[i]]);
    }
    cout << ans << endl;
    return 0;
}


