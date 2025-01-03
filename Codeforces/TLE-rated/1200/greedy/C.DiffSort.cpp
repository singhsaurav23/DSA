//pattern always n-2 <= n-1 and usin this make everyone smaller

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

        for (i = 0; i < n; i++) cin >> v[i];
        if (is_sorted(v.begin(), v.end())) cout << 0 << endl;
        else if (v[n - 2] > v[n - 1]) cout << -1 << endl;
        else {

            if (v[n - 1] < 0) cout << -1 << endl;
            else {
                cout << n - 2 << endl;
                for (i = n - 3; i >= 0; i--) {
                    cout << i + 1 << " " << n - 1 << " " << n << endl;
                }
            }
        }
    }
    return 0;
}