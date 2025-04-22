/*
Codeforces Round 856 (Div. 2)
The score of a sequence[s1, s2, …, sd]
is defined as s1⋅s2⋅…⋅sdd!
, where d != 1⋅2⋅…⋅d
.In particular, the score of an empty sequence is 1
.

so s1/n s2/n-1.......sn/1 find the max sequnece(subarray from last i) usng binary search as increasing order
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, n;
        cin >> n;
        vector<ll> v(n);
        for (i = 0; i < n; i++) cin >> v[i];
        vector<ll> tt;
        for (i = n - 1; i >= 0; i--) {
            ll l = 0, r = i, ans = r;
            while (l <= r) {
                ll m = l + (r - l) / 2;

                if ((float)(v[m] / (i - m + 1)) >= 1.0) {
                    ans = m;
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            tt.push_back(i - ans + 1);
        }
        for (i = tt.size() - 1; i >= 0; i--) cout << tt[i] << " ";
        cout << endl;
    }
    return 0;
}

