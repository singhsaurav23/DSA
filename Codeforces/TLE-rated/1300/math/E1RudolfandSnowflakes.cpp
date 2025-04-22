//brute force to precompute as tc is not big
//Codeforces Round 883 (Div. 3)
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll t;
    cin >> t;
    unordered_map<ll, bool> mp;
    ll j = 2;
    while (j <= 1e6) {
        ll i = (j * j) + (j + 1), p = j * j;
        while (i <= 1e6) {
            mp[i] = true;
            p *= j;
            i += p;
        }
        j++;
    }
    while (t--) {
        ll n;
        cin >> n;
        if (mp[n] == true) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

