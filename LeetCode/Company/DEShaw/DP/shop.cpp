// knapsack problem
// given happiness, weights of array you can buy
// constraint max limit and min limit for each i
// max amount you can use
// find maximum hapiness in the given constraints

/*
Testcase->
TC->O(N*M*(max-min)) SC->O(N*M)
*/
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int shop(ll i, vector<ll>& v, vector<ll>& h, vector<ll>& mi, vector<ll>& ma, ll m, vector<vector<int>>& dp) {
    if (m == 0) {
        return 0;
    }
    if (i == v.size()) {
        return 0;
    }
    if (dp[i][m] != -1) return dp[i][m];
    ll t = 0, nt = 0;
    for (ll j = mi[i]; j <= ma[i]; j++) {
        if ((j * v[i]) <= m)
            t = max(t, j * h[i] + shop(i + 1, v, h, mi, ma, m - (j * v[i]), dp));
        else break;
    }
    return dp[i][m] = t;
}


int main() {
    ll n, m, i;
    cin >> n;
    vector<ll> cost(n), hap(n), mi(n), ma(n);
    for (i = 0; i < n; i++) cin >> cost[i];
    for (i = 0; i < n; i++) cin >> hap[i];
    for (i = 0; i < n; i++) cin >> mi[i];
    for (i = 0; i < n; i++) cin >> ma[i];
    cin >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << shop(0, cost, hap, mi, ma, m, dp) << endl;
    return 0;
}

//Bottom up->Tabulation

#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main() {
    ll n, m, i, j, k;
    cin >> n;
    vector<ll> v(n), h(n), mi(n), ma(n);
    for (i = 0; i < n; i++) cin >> v[i];
    for (i = 0; i < n; i++) cin >> h[i];
    for (i = 0; i < n; i++) cin >> mi[i];
    for (i = 0; i < n; i++) cin >> ma[i];
    cin >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            ll t = 0;
            for (k = mi[i - 1]; k <= ma[i - 1]; k++) {
                if ((k * v[i - 1]) <= j)
                    t = max(t, k * h[i - 1] + dp[i - 1][j - (k * v[i - 1])]);
                else break;
            }
            dp[i][j] = t;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}

//space optimized O(M)
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main() {
    ll n, m, i, j, k;
    cin >> n;
    vector<ll> v(n), h(n), mi(n), ma(n);
    for (i = 0; i < n; i++) cin >> v[i];
    for (i = 0; i < n; i++) cin >> h[i];
    for (i = 0; i < n; i++) cin >> mi[i];
    for (i = 0; i < n; i++) cin >> ma[i];
    cin >> m;

    vector<ll> cur(m + 1, 0), prev(m + 1, 0);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            ll t = 0;
            for (k = mi[i - 1]; k <= ma[i - 1]; k++) {
                if ((k * v[i - 1]) <= j)
                    t = max(t, k * h[i - 1] + prev[j - (k * v[i - 1])]);
                else break;
            }
            cur[j] = t;
        }
        prev = cur;
    }
    cout << prev[m] << endl;
    return 0;
}