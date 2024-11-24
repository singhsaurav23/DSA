#include <bits/stdc++.h>

using namespace std;

#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);


#define int long long

void CoderAbhi27() {
    int n, m, v;
    cin >> n >> m >> v;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    } // n

    vector<int> pr(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pr[i] = pr[i - 1] + a[i]; // n

    vector<int> v1, v2;
    v1.push_back(1);
    v2.push_back(n);

    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += a[i];
        if (s >= v) {
            v1.push_back(i + 1);
            s = 0;
        }
    } // n

    s = 0;
    for (int i = n; i >= 1; i--) {
        s += a[i];
        if (s >= v) {
            v2.push_back(i - 1);
            s = 0;
        }
    } // n

    if (v1.size() - 1 < m) {
        cout << "-1\n";
        return;
    }

    int ans = 0;
    for (int i = 0; i <= m; i++) {
        // x = i, y = m-i
        int l = v1[i], r = v2[m - i];
        int sum = pr[r] - pr[l - 1];
        ans = max(ans, sum);
    } // m
    cout << ans << '\n';
}

// tc -> O(n+m)
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