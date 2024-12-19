// trick to sort you need to take max steps till i index and then sort and then perform binary search to find how max steps can be taken
//upper_bound faster tha b_search code sometimes

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, n, q;
        cin >> n >> q;
        vector<ll> v(n), pref(n);
        for (i = 0; i < n; i++) {
            cin >> v[i];
            //   prefm[i]=v[i];
            pref[i] = v[i];
            if (i > 0) {
                pref[i] += pref[i - 1];
                v[i] = max(v[i], v[i - 1]);
            }
        }

        // vector<ll> qq(q);
        ll kk;
        for (i = 0; i < q; i++) {
            cin >> kk;
            auto x = upper_bound(v.begin(), v.end(), kk);
            ll xx = x - v.begin() - 1;
            if (v[xx] <= kk && xx >= 0 && xx <= v.size() - 1)
                cout << pref[xx] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}