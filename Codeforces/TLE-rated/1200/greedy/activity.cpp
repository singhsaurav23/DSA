/*Codeforces Round 916 (Div. 3)
D. Three Activities*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> getMax(vector<ll>& a) {
    ll ma1 = -1, ma2 = -1, ma3 = -1, i;
    for (i = 0; i < a.size(); i++) {

        if (ma1 == -1) ma1 = i;
        else if (a[ma1] < a[i]) {
            ma3 = ma2;
            ma2 = ma1;
            ma1 = i;
        }
        else if (ma2 == -1) ma2 = i;

        else if (a[ma2] < a[i]) {
            ma3 = ma2;
            ma2 = i;
        }
        else if (ma3 == -1) ma3 = i;
        else if (a[ma3] < a[i]) ma3 = i;
    }
    return { ma1,ma2,ma3 };
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, i, j, k;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        vector<ll> c(n);
        for (i = 0; i < n; i++) cin >> a[i];
        for (i = 0; i < n; i++) cin >> b[i];
        for (i = 0; i < n; i++) cin >> c[i];
        vector<ll> aa = getMax(a);
        vector<ll> bb = getMax(b);
        vector<ll> cc = getMax(c);
        ll ans = 0;
        // comparing each 9 numbers among each other
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                for (k = 0; k < 3; k++) {
                    if (aa[i] != bb[j] && aa[i] != cc[k] && bb[j] != cc[k]) {
                        ans = max(ans, a[aa[i]] + b[bb[j]] + c[cc[k]]);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}