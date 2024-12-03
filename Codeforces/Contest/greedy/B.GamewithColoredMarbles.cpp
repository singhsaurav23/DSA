//greedily choose element with minimum number of times left
//nlogn

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, n, x;
        cin >> n;
        set<ll> s;
        unordered_map<ll, ll> mp;

        for (i = 0; i < n; i++) { cin >> x; mp[x]++; }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        for (auto it : mp) {
            pq.push({ it.second,it.first });
        }
        ll c = 0;
        while (!pq.empty()) {
            ll y = pq.top().first;
            ll elem = pq.top().second;
            if (c == 0) { s.insert(elem); mp[elem]--; c = 1; }
            else c = 0;
            pq.pop();
            if (y > 1)
                pq.push({ y - 1,elem });
        }
        ll ans = s.size();
        for (auto it : s) {
            if (mp[it] == 0) ans++;
        }
        cout << ans << endl;
    }
}

//optimized->n
// you can only pick complete color of that if number of colors is 1 otherwise bob will come and take it

#include <bits/stdc++.h>

using namespace std;

#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);


void CoderAbhi27() {
    int n;
    cin >> n;
    vector<int> a(n), freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    } // n
    int ans = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        if (freq[i] > 1)
            ans++;
        if (freq[i] == 1)
            c++;
    } // n
    ans += (c + 1) / 2 * 2;
    cout << ans << '\n';
}

// tc -> O(n)
// sc -> O(n)

int32_t main() {
    fastIO;

    int t = 1;
    cin >> t;
    while (t--) {
        CoderAbhi27();
    }
    return 0;
}