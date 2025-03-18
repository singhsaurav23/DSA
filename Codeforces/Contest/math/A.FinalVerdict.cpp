//codeforces 1008 div2
// split it into k subsqruneces tsuch that avg is k ...
// just divide by k it shuld give k simple maths

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, i, k, x, s = 0;
        cin >> n >> k;
        // cout<<ceil(1.2);
        for (i = 0; i < n; i++) { cin >> x; s += x; }
        if (s % k == 0 && s / k == n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}