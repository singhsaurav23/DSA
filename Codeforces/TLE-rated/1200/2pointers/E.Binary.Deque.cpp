//miantain largest subarray with sum = s and ans=n-largest suarray size
//binary search 2nd solution

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, s, i, j;
        cin >> n >> s;
        vector<ll> v(n);
        for (i = 0; i < n; i++) cin >> v[i];

        for (i = 1; i < n; i++) v[i] += v[i - 1];
        i = 0, j = 1;
        ll ans = 0;
        while (j < n) {
            while (i < j && ((v[j] - v[i]) > s)) i++;
            if ((i == 0 && v[i] == 1) || (i != 0 && v[i - 1] < v[i]))
                ans = max(ans, j - i);
            else ans = max(ans, j - i + 1);
            j++;
        }
        if (v[n - 1] < s) cout << -1 << endl;
        else if (v[n - 1] == s) cout << 0 << endl;
        else
            cout << n - ans << endl;
    }
}