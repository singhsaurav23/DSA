//pattern finding that suf[i]+suf[j]+......suf[m-1] >=k as m partitions and pick m elemnets that give sum greater than k
//Educational CF ROund 172 C
// main point is to find the pattern that whenever we do partition left ans will remain same only
// right answers will have value 1+ as each partiotion increases the value by 1
// visualize the formula by examples start with m=2 whenevr partion suf[i]*m(m=1) mwill incr if more partiton
// 1 for b alic=0 so -1 maintain suffix

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        ll ans = 1;
        vector<ll> suf(n, 0);
        for (i = n - 1; i >= 0; i--) {
            if (s[i] == '0') suf[i]--;
            else suf[i]++;
            if (i != n - 1) suf[i] += suf[i + 1];
        }
        priority_queue<ll> pq;
        for (i = 1; i < n; i++) pq.push(suf[i]);
        ll c = 0;
        while (!pq.empty()) {
            c += pq.top();
            if (c >= k) break;
            pq.pop();
            ans++;
        }
        if (c < k) cout << -1 << endl;
        else
            cout << ans + 1 << endl;
    }
    return 0;
}