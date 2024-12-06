// minatain two pointers starting from first and end and you know elements are 1 to n so min is 1 and max is n

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, n, j;
        cin >> n;
        vector<ll> v(n);

        for (i = 0; i < n; i++) { cin >> v[i]; }
        if (n <= 2) cout << -1 << endl;
        else {
            i = 0, j = n - 1;
            ll mi = 1, ma = n;
            while (i <= j) {
                if (v[i] == mi) { i++; mi++; }
                else if (v[i] == ma) { i++; ma--; }
                else if (v[j] == mi) { j--; mi++; }
                else if (v[j] == ma) { j--; ma--; }
                else break;
            }
            if (i <= j) cout << i + 1 << " " << j + 1 << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}