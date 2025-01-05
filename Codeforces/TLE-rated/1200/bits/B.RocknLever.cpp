//ans will be greater than equal tothose pairs where 1s are there in msb and 0s same type

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, i, j; cin >> n;
        vector<ll> v(n);
        for (i = 0; i < n; i++) cin >> v[i];
        ll c1 = 0, c = 0;
        ll sum = 0;
        for (i = 29; i >= 0; i--) {
            c1 = 0; c = 0;
            for (j = 0; j < n; j++) {
                if (v[j] == -1) continue;
                if (((1 << i) & v[j]) != 0) { v[j] = -1; c1++; }
                else c++;
            }
            sum += (c1 * (c1 - 1)) / 2;
        }
        sum += (c * (c - 1)) / 2;
        cout << sum << endl;
    }
    return 0;
}
