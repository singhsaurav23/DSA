//codeforces 918 div 4

#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, i;
        cin >> n;
        vector<ll> v(n);
        for (i = 0; i < n; i++) { cin >> v[i]; if (i % 2) v[i] = -1 * v[i]; }
        ll c = 0;
        set<ll> st;
        st.insert(v[0]);
        for (i = 1; i < n; i++) { v[i] += v[i - 1]; ll x = st.size(); st.insert(v[i]); if (v[i] == 0 || st.size() == x) { c = 1; break; } }

        if (c == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}