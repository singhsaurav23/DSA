//Codeforces Round 790 (Div. 4)
//DFS approach to store black white per node and check

#include<bits/stdc++.h>
using namespace std;
#define ll long long


pair<ll, ll> dfs(ll node, ll par, vector<ll>* adj, ll& c, string& color) {
    int b = 0, w = 0;
    if (color[node - 1] == 'B') b++;
    else w++;

    for (auto it : adj[node]) {
        if (it != par) {
            pair<ll, ll> p = dfs(it, node, adj, c, color);
            b += p.first;
            w += p.second;
        }
    }
    if (b == w) c++;
    return { b,w };
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, x, i;
        cin >> n;
        vector<ll> adj[n + 1];
        vector<bool> color;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            adj[x].push_back(i + 2);
        }
        string s;
        cin >> s;
        ll c = 0;
        dfs(1, 1, adj, c, s);
        cout << c << endl;

    }
    return 0;
}

//optimize method
#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll dfs(ll node, vector<ll>* adj, ll& c, string& color) {
    int b = 0;
    if (color[node - 1] == 'B') b++;
    else b--;

    for (auto it : adj[node]) {
        b += dfs(it, adj, c, color);
    }
    if (b == 0) c++;
    return b;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, x, i;
        cin >> n;
        vector<ll> adj[n + 1];
        vector<bool> color;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            adj[x].push_back(i + 2);
        }
        string s;
        cin >> s;
        ll c = 0;
        dfs(1, adj, c, s);
        cout << c << endl;

    }
    return 0;
}


