#include <bits/stdc++.h>

using namespace std;

#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend()); // nlog
    int s = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        if (s <= k) {
            ans = k - s;
        }
        else
            break;
    } // n
    cout << ans << '\n';
}

// tc -> O(nlogn)
// sc -> O(n)

int32_t main() {
    fastIO;

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}