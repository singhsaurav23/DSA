#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll i, x;
        map<ll, ll> mp;
        for (i = 0; i < n; i++) { cin >> x; mp[x]++; }
        ll c = 0;
        for (auto it : mp) {
            c += it.second / 2;
        }
        cout << c << endl;
    }
    return 0;
}