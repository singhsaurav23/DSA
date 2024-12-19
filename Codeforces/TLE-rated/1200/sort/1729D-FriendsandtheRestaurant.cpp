/*	Intuition
sorting + 2pointers or sorting + multiset(for duplicATES) + greedy for taking differnece as x + y <= x1 + y1 = > x - x1 <= y1 - y
 find x-x1 and for each that find minimum that is greater than equal to =>lower_bound */

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, n;
        cin >> n;
        vector<ll> x(n), y(n);
        for (i = 0; i < n; i++) cin >> x[i];
        for (i = 0; i < n; i++) cin >> y[i];
        multiset<ll> v;
        for (i = 0; i < n; i++) {
            v.insert(y[i] - x[i]);
            //cout<<y[i]-x[i]<<" ";
        }
        ll ans = 0;
        auto it = v.begin();
        while (v.size() > 1) {
            ll x = -1 * (*it);

            v.erase(it);
            auto yy = v.lower_bound(x);

            if (yy != v.end()) {
                //   cout<<x<<" ";
                  // cout<<*yy<<" ";
                v.erase(yy);

                ans++;
            }
            //cout<<v.size()<<" ";
            if (v.size() <= 1) break;
            it = v.begin();
        }
        cout << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll>x(n), y(n);
    vector<pair<ll, int>>dif(n);

    for (auto& i : x) cin >> i;
    for (auto& i : y) cin >> i;
    for (int i = 0; i < n; i++) {
        dif[i].first = y[i] - x[i];
        dif[i].second = i;
    }
    sort(dif.begin(), dif.end());
    reverse(dif.begin(), dif.end());

    int j = n - 1, cnt = 0;

    for (int i = 0; i < n; i++) {
        while (j > i && dif[i].first + dif[j].first < 0) j--;
        if (j <= i) break;
        cnt++; j--;
    }
    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}