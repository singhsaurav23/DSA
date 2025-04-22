//question was to divide with a divisor for a[i] and multiply to a[j] with thatndivisor , at last after some operations make everyone equal...
// that means prime factors of all numbers should be eual
// store prime factors and see if denomination can be distributed evenly to n numbers

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, n, j;
        cin >> n;
        vector<ll> v(n);
        unordered_map<ll, ll> mp;
        for (i = 0; i < n; i++) cin >> v[i];
        for (i = 0; i < n; i++) {
            for (j = 2; j * j <= v[i]; j++) {        //printing prime factors
                while (v[i] % j == 0) {
                    v[i] /= j;
                    mp[j]++;
                }
            }
            if (v[i] > 1) mp[v[i]]++;             // this line shows that for printing prime factors , if number is still > 1 , it's first prime like 2,3,5 
        }
        bool c = false;
        for (auto it : mp) {
            if (it.second % n != 0) { c = true; break; }
        }
        if (c) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}

