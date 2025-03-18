//codeforces 1008 div2 c -> try to get distuintc number only if greater than highest number
// if 6 numbers h->high and l->low
// h3+h2+h1+l3(3rd lowest)(all big numbers together) - l2-l1 this number will be positive try diff testcase
// so number would be h1+.... greater than the highest number always
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, j, i;
        cin >> n;
        vector<ll> v(2 * n);
        for (i = 0; i < 2 * n; i++) cin >> v[i];
        sort(v.begin(), v.end());

        vector<ll> z;
        for (j = 2 * n - 1, i = 0; j >= n, i < n; j--, i++) {
            z.push_back(v[j]);
            z.push_back(v[i]);
        }
        z.push_back(0);
        swap(z[2 * n], z[2 * n - 1]);
        ll x = 0, y = 0;
        for (i = 0; i < z.size(); i++) { if (i % 2 == 0) x += z[i]; else y += z[i]; }
        z[2 * n - 1] = abs(x - y);
        for (i = 0; i < z.size(); i++) cout << z[i] << " ";
        cout << endl;
    }
    return 0;
}