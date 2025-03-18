//maintain the left different using traversal and array dp Codeforces Round 923 (Div. 3)

#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, q, i, x, y;
        cin >> n;
        vector<ll> v(n);
        for (i = 0; i < n; i++) cin >> v[i];
        cin >> q;
        vector<ll> l(n, -1);
        for (i = 1; i < n; i++) {
            l[i] = l[i - 1];
            if (v[i] != v[i - 1]) l[i] = i - 1;
        }
        for (i = 0; i < q; i++) {
            cin >> x >> y;
            if (v[x - 1] != v[y - 1]) cout << x << " " << y << "\n";
            else {
                if (l[y - 1] != -1 && l[y - 1] + 1 >= x) cout << l[y - 1] + 1 << " " << y << "\n";
                else cout << -1 << " " << -1 << "\n";
            }
        }
    }
    return 0;
}
