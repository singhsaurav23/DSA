// Find which number if not used will not affect the OR so maintain map of numbers cnt, if that number is unqiue cnt it cannot be removed, if one number can be removed then YES else NO

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, i, j;
        cin >> n;
        unordered_map<ll, ll> mp;
        vector<vector<ll>> vv;
        for (i = 0; i < n; i++) {
            ll k;
            cin >> k;
            ll x;
            vector<ll> v;
            for (j = 0; j < k; j++) {
                cin >> x;
                v.push_back(x);
                mp[x]++;
            }
            vv.push_back(v);
        }
        ll c = 0;
        for (i = 0; i < vv.size(); i++) {
            c = 0;
            for (j = 0; j < vv[i].size(); j++) {
                if (mp[vv[i][j]] == 1) { c = 1; break; }
            }
            if (c == 0) break;
        }
        if (c == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

