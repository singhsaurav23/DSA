//maximize and by performing k operations of setting bit start from msb to lsb
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, i, k, j;
        cin >> n >> k;
        vector<ll> v(n);
        for (i = 0; i < n; i++) {
            cin >> v[i];
        }
        ll ans = 0;
        for (i = 30; i >= 0; i--) {
            ll c = 0;
            for (j = 0; j < n; j++) {
                if ((v[j] & (1 << i)) == 0) c++;
            }
            if (c == 0 || k >= c) {
                ans = (1 << i) | ans;
                k -= c;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

