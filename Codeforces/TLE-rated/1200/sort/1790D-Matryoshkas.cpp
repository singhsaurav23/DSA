// sort and greedy intuition to find maximum number of consecutive sets

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, n;
        cin >> n;
        vector<ll> v(n);
        for (i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        ll p = 0, ans = 0;
        for (i = 0; i < n; i++) {
            ll c = 1;
            if (i == 0 || (v[i] - 1) != (v[i - 1])) p = 0;
            while ((i + 1) < n && v[i] == v[i + 1]) { c++; i++; }

            if (c > p) ans += c - p;
            p = c;
        }
        cout << ans << endl;
    }
    return 0;
}