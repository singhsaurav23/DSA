/*l2 <= y = xk * *n <= r2
l2/k**n <= x <= r2/k**n   -> n =1 till n<=1e9 multiply k erverytime so for each y range find the correct x range numbers and summation*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll l1, r1, l2, r2, k;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        ll i = 1, ans = 0;
        while (i <= 1e9) {
            ans += max(0LL, 1 + (min(r2 / i, r1) - max(((l2 + i - 1) / i), l1)));
            i *= k;
        }
        cout << ans << "\n";
    }
}