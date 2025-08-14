//check all cases for last elment of s and t
// and v[i] which category to lie,, make the large elemnt always largest
// minimize penalty 
#include <bits/stdc++.h>
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
        vector<ll> a, b;
        a.push_back(v[0]);
        for (i = 1; i < n; i++) {
            if (b.size() > 0 && v[i] <= a[a.size() - 1] && v[i] <= b[b.size() - 1]) {
                if (b[b.size() - 1] < a[a.size() - 1]) b.push_back(v[i]);
                else a.push_back(v[i]);
            }
            else if (b.size() > 0 && v[i] > a[a.size() - 1] && v[i] > b[b.size() - 1]) {
                if (b[b.size() - 1] < a[a.size() - 1]) b.push_back(v[i]);
                else a.push_back(v[i]);
            }
            else if (v[i] <= a[a.size() - 1]) a.push_back(v[i]);
            else b.push_back(v[i]);
        }
        // cout<<b.
        auto num = [](vector<ll>& x) {
            ll prev = x[0], c1 = 0;
            for (ll i = 1; i < x.size(); i++) {
                if (prev < x[i]) c1++;
                prev = x[i];
            }
            return c1;
        };
        //  cout<<num(b)<<endl;
        if (b.size() == 0) cout << num(a) << endl;
        else cout << num(a) + num(b) << endl;

    }
    return 0;
}


