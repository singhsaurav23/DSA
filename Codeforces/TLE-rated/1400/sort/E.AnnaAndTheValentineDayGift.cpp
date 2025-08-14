// intutiove thinking sorting according to number of 0s
// only matter number of digits coz 10**m is the constraint for game

#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll many(ll x) {
    ll c2 = 0;
    while (x != 0) {
        if (x % 10 == 0) c2++;
        else break;
        x = x / 10;
    }
    return c2;
}

ll cnnt(ll x) {
    ll c2 = 0;
    while (x != 0) {
        c2++;
        x = x / 10;
    }
    return c2;
}

static bool comp(ll a, ll b) {
    ll x = a, c1 = many(x);
    x = b;
    ll c2 = many(x);
    return c1 < c2;
}


int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, n, m;
        cin >> n >> m;
        vector<ll> v(n);
        vector<ll> t;
        for (i = 0; i < n; i++) cin >> v[i];
        for (i = 0; i < n; i++) {
            if (v[i] % 10 == 0) t.push_back(v[i]);
        }
        sort(t.begin(), t.end(), comp);
        ll zero = 0;
        ll nn = t.size();

        for (i = nn - 1; i >= 0; i -= 2) {
            zero += many(t[i]);
        }
        ll sum = 0;
        for (i = 0; i < n; i++) {
            sum += cnnt(v[i]);
        }
        if (sum - zero >= (m + 1)) cout << "Sasha" << endl;
        else cout << "Anna" << endl;
    }
    return 0;
}


