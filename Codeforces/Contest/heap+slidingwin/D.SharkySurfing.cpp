//Codeforces Round 988 (Div. 3)
// add the value u can collect and check max if that can withdraw that obstacle

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, j, n, m, l;
        cin >> n >> m >> l;
        vector<pair<ll, ll>> vb(n), vp(m);
        for (i = 0; i < n; i++) cin >> vb[i].first >> vb[i].second;
        for (i = 0; i < m; i++) cin >> vp[i].first >> vp[i].second;

        j = 0;
        priority_queue<ll> pq;
        ll sum = 1, c = 0;
        for (i = 0; i < m; i++) {
            while (vp[i].first > vb[j].first && j < n) {
                ll x = (vb[j].second - vb[j].first + 2);

                if (sum < x) {
                    while (!pq.empty() && sum < x) {
                        sum += pq.top();
                        pq.pop();
                        c++;
                    }
                    //   cout<<sum<<" "<<x<<"\n";
                    if (sum < x) { c = -1; break; }
                }
                j++;
            }
            if (c == -1) break;
            pq.push(vp[i].second);

        }

        while (j < n && c != -1) {
            ll x = (vb[j].second - vb[j].first + 2);

            if (sum < x) {
                while (!pq.empty() && sum < x) {
                    sum += pq.top();
                    pq.pop();
                    c++;
                }
                // cout<<sum<<" "<<c<<"\n";
                if (sum < x) { c = -1; break; }
            }
            j++;
        }
        cout << c << endl;
    }
    return 0;
}