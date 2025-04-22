//sort and binary search

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, i, x;
        cin >> n;
        vector<pair<ll, ll>> vp;
        for (i = 1; i <= n; i++) {
            cin >> x;
            if (x < i) {
                vp.push_back({ x,i });
            }
        }
        sort(vp.begin(), vp.end());
        ll cnt = 0;
        for (i = 0; i < vp.size(); i++) {
            ll y = vp[i].second;
            pair<ll, ll> p = { y,INT_MAX };
            auto it = upper_bound(vp.begin(), vp.end(), p);
            if (it != vp.end()) {
                ll xx = it - vp.begin();
                cnt += vp.size() - xx;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

