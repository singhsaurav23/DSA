//n(logn)(logn)
// select mid and cehck if it is using sorting
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_k(vector<ll>& v, ll m, ll h) {
    ll i, s = 0;
    vector<ll> t(m);
    for (i = 0; i < m; i++) t[i] = v[i];
    sort(t.begin(), t.end());
    for (i = m - 1; i >= 0; i -= 2) {
        s += t[i];
    }
    if (s > h) return false;
    return true;
}

int main() {
    ll n, h, i;
    cin >> n >> h;
    vector<ll> v(n);
    for (i = 0; i < n; i++) cin >> v[i];
    ll l = 1, r = n, ans = 0;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        if (is_k(v, m, h)) {
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    cout << ans << endl;
}




// sort and store position then binary search and check On(logn)