//Codeforces round 976 (Div. 2) and Divide By Zero 9.0
//D. Connect the dots
// find for each n and d=10 dp, form DSU ignore repeated arcs iterations maintain max i j,-> n,10  

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> par, siize;

int findPar(int x) {
    if (par[x] == x) return x;
    return par[x] = findPar(par[x]);
}

void unionSize(int u, int v) {
    int paru = findPar(u);
    int parv = findPar(v);
    if (paru != parv) { // Avoid redundant unions
        if (siize[paru] < siize[parv]) {
            par[paru] = parv;
            siize[parv] += siize[paru];
        }
        else {
            par[parv] = paru;
            siize[paru] += siize[parv];
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, c = 0;
        cin >> n >> m;

        // Reinitialize par and siize vectors for each test case
        par.assign(n + 1, 0);
        siize.assign(n + 1, 1);

        for (ll i = 1; i <= n; i++) {
            par[i] = i; // Initialize each element as its own parent
        }

        vector<vector<ll>> dp(n + 1, vector<ll>(11, 0));

        // Input and process dp array
        while (m--) {
            ll a, d, k;
            cin >> a >> d >> k;
            dp[a][d] = max(dp[a][d], k);
        }

        // Perform union operations based on conditions
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= 10; j++) {
                ll it = dp[i][j];
                ll pos = i;
                while (it > 0 && (pos + j) <= n) {
                    it--;
                    unionSize(pos, pos + j);
                    dp[pos][j] = 0;
                    pos += j;

                    it = max(dp[pos][j], it);  // Update the remaining count in dp
                }
            }
        }

        // Count unique components
        for (ll i = 1; i <= n; i++) {
            if (findPar(i) == i) c++;
        }
        cout << c << endl;
    }

    return 0;
}
