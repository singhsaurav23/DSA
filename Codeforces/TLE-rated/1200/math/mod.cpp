/* B. Make Almost Equal With Mod 
Pinely Round 3 (Div. 1 + Div. 2)*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, i, x, c = 0;
        cin >> n;
        vector<ll> v(n);
        for (i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] % 2 != 0) { c++; }
        }
        if (c > 0 && c < n)
            cout << 2 << endl;
        else {
            c = 0;
            ll k = 4; set<ll> st;
            while (st.size() != 2) {
                for (i = 0; i < n; i++) {
                    st.insert(v[i] % k);
                }
                if (st.size() == 2) break;
                k = k * 2;
                st.clear();
            }
            cout << k << endl;
        }
    }
    return 0;
}