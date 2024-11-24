#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll k, i = 0, j = 1;
        cin >> k;
        vector<ll> v(k);
        map<ll, ll> mp;
        for (i = 0; i < k; i++) { cin >> v[i]; mp[v[i]] = 1; }
        j = k - 2;
        sort(v.begin(), v.end());
        i = 0;
        for (i = 0; i < k; i++) {
            ll x = j / v[i];
            if (j % v[i] == 0) {
                if (mp[x] == 1) {
                    cout << v[i] << " " << x << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}