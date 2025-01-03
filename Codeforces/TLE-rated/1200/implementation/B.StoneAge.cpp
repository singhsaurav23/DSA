#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll n, q, i, s = 0;
    cin >> n >> q;
    vector<ll> v(n); map<ll, ll> mp;
    for (i = 0; i < n; i++) { cin >> v[i]; s += v[i]; mp[i] = v[i]; }

    ll d = -1;
    for (i = 0; i < q; i++) {
        ll qq;
        cin >> qq;
        if (qq == 1) {
            ll y, z;
            cin >> y >> z;
            if (mp.find(y - 1) == mp.end())
            {
                if (d != -1) s -= d;
            }
            else s -= mp[y - 1];
            s += z;
            mp[y - 1] = z;
            cout << s << endl;
        }
        else {
            ll x;
            cin >> x;
            d = x;
            mp.clear();
            s = x * n;
            cout << s << endl;
        }
    }

    return 0;
}
