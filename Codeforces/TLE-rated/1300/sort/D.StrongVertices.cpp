#include<bits/stdc++.h>
using namespace std;
#define ll long long

// au-av >= bu-bv   so au-bu >= av-bv  one vector now sort and max elements will be reachable to every so eaul max elemnts
//Codeforces Round 891 (Div. 3)

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, n, j;
        cin >> n;
        vector<ll> a(n), b(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<pair<ll, ll>> vp(n);
        for (i = 0; i < n; i++) {
            vp[i].first = a[i] - b[i];
            vp[i].second = i + 1;
        }
        sort(vp.begin(), vp.end());

        for (i = n - 2; i >= 0; i--) {
            if (vp[i].first == vp[i + 1].first) continue;
            else break;
        }
        cout << n - (i + 1) << "\n";
        for (j = i + 1; j < n; j++) {
            cout << vp[j].second << " ";
        }
        cout << endl;
    }
    return 0;
}

