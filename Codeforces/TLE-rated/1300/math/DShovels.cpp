//pattern aND PRIME factors divisility
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, i, k;
		cin >> n >> k;
		if (n <= k) cout << 1 << endl;
		else {

			ll ans = n;
			for (i = 2; i * i <= n; i++) {
				if (i <= k && n % i == 0) {
					ans = min(ans, n / i);
				}
				if (n % i == 0 && (n / i) <= k) ans = min(ans, i);
			}

			cout << ans << endl;
		}
	}



	return 0;
}