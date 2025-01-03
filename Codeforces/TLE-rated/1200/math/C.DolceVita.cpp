// sort the array find prefix sum for each index find the max it can give to packets till cost
// s,s+n,s+2n.... it increase in this form so x=(cost-s)/n -> will give how many x*n required to get cost taking 3 shops then 2 shops etc...
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, d, i;
        cin >> n >> d;
        vector<ll> v(n);
        for (i = 0; i < n; i++) cin >> v[i];

        sort(v.begin(), v.end());
        ll dd = 0, cnt = 0;
        for (i = 1; i < n; i++) v[i] += v[i - 1];
        for (i = n - 1; i >= 0; i--) {
            ll s = v[i] + (i + 1) * dd;
            if (d >= s) {
                ll x = ((d - s) / (i + 1)) + 1;
                dd += x;
                cnt += (i + 1) * x;
            }
            //cout<<cnt<<" "<<dd<<" ";
        }
        cout << cnt << "\n";
    }
    return 0;
}


