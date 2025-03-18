/*
Question: In a game of chess, you are given that there are n players, and a list of m matches between players. If a player has won a match from another player then it is said that the winning player has higher rank than the losing player. Also, if ith player wins from jth player then ith player will win from all the players jth player won from. You're tasked to return the maximum number of players for which you can deterministically identify the ranks.


Example: n=5, m=4, matches=[[A,B],[B,C],[C,E],[D,C]]


Output: 2 (c,e)
mix of dp+ dfs + intuution of maintaining left losses and right wins plus which should be interacted with everyone
brute force n*n
Aksed in Google L3 L4 and amazon L5
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int dfs(ll i, vector<ll>* adj, vector<ll>& v) {
    if (v[i] != -1) {
        return v[i];
    }
    int res = 0, c = 0;
    for (auto it : adj[i]) {
        res += dfs(it, adj, v);
        c++;
    }
    return v[i] = res + c;
}




int main() {
    ll n, m, x, y, i;
    cin >> n >> m;
    vector<ll> right[n], left[n];
    for (i = 0; i < m; i++) {
        cin >> x >> y;
        right[x].push_back(y);
        left[y].push_back(x);
    }
    vector<ll> r(n, -1), l(n, -1);

    for (i = 0; i < n; i++) {
        if (r[i] == -1)
            dfs(i, right, r);
    }
    for (i = 0; i < n; i++) {
        if (l[i] == -1)
            dfs(i, left, l);
    }
    ll ans = 0;
    for (i = 0; i < n; i++) {
        if (l[i] == -1) l[i] = 0;
        if (r[i] == -1) r[i] = 0;

        if (l[i] + r[i] >= n - 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
