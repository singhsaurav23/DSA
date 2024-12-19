//CIRCULAR ARRAY->take  from max segments to least segments use heap to maintain factor of 1 and 2 two heaps take max of them
// CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!)

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, n, m;
        cin >> n >> m;
        vector<ll> v(m);
        for (i = 0; i < m; i++) cin >> v[i];
        sort(v.begin(), v.end());
        priority_queue<ll> pq1, pq2;

        if ((n - v[m - 1] - 1 + v[0]) > 0)
            pq1.push(n - v[m - 1] + v[0] - 1);
        for (i = 0; i < m - 1; i++) {
            if ((v[i + 1] - v[i] - 1) > 0)
                pq1.push(v[i + 1] - v[i] - 1);

        }
        ll d = 0, ans = 0;

        while (!pq1.empty() || !pq2.empty()) {
            ll m1 = 0, m2 = 0;
            if (!pq1.empty())
                m1 = pq1.top();
            if (!pq2.empty())
                m2 = pq2.top();

            m1 = m1 - 2 * d;
            m2 = m2 - d;
            if (m1 <= 0 && m2 <= 0) break;
            // cout<<m1<<" "<<m2<<" ";
            if (m1 > m2) {
                ans++;
                pq1.pop();
                if ((m1 + d - 1) > 0)
                    pq2.push(m1 + d - 1);
            }
            else {
                ans += m2;
                pq2.pop();
            }
            // cout<<ans<<"\n";
            d++;
        }
        if (m == 1) cout << 2 << endl;
        else
            cout << n - ans << endl;
    }
    return 0;
}