//binary search if elment exist
//2nd approach instead of binary search maintain a hashmap
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, i, s = 0;
    cin >> n;
    vector<ll> v(n), t(n);
    for (i = 0; i < n; i++) {
        cin >> v[i];
        t[i] = v[i];
        s += v[i];
    }
    sort(t.begin(), t.end());
    vector<ll> ans;
    for (i = 0; i < n; i++) {
        s -= v[i];
        if (s % 2 != 0) { s += v[i]; continue; }
        ll x = s / 2;
        ll l = 0, r = n - 1, c = 0;

        // cout<<i<<" "<<s<<" "<<x<<"\n";
        while (l <= r) {
            ll m = l + (r - l) / 2;
            if (t[m] == x) {
                if (x == v[i]) {
                    if ((m - 1) >= 0 && t[m - 1] == t[m]) { c = 1; break; }
                    if ((m + 1) < n && t[m + 1] == t[m]) { c = 1; break; }
                    break;
                }
                else {
                    c = 1; break;
                }
            }
            else if (t[m] < x) l = m + 1;
            else r = m - 1;
        }
        if (c == 1) ans.push_back(i + 1);
        s += v[i];
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}




