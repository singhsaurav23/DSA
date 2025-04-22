#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353


//formula = noways to select one from each batch block (nc1 , n1c1, n2c1....) * no of ways to order removed element = fact(len-1 + len1-1...)
// order matters = select some elments for the answer * permutation of removed elment for order

int main() {
    ll t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll i, n = s.size(), c = 0, ans = 0, x = 0;
        unordered_map<ll, ll> mp;
        for (i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) c++;
            else {
                ans += c;
                if (c >= 1) x += c;
                mp[c + 1]++;
                c = 0;

            }
        }
        if (c != 0) {
            ans += c;
            if (c >= 1) x += c;
            mp[c + 1]++;
        }

        ll ans2 = 1;


        for (auto it : mp) {
            while (it.second >= 1) {
                ans2 = (ans2 % mod * it.first % mod) % mod;
                it.second--;
            }
        }

        for (ll i = 2; i <= x; i++) {
            ans2 = (ans2 % mod * i % mod) % mod;
        }

        cout << ans << " " << ans2 << endl;
    }
    return 0;
}

