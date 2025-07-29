//find pattern to get the value

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (n % 2 == 0) cout << n / 2 << " " << n / 2 << "\n";
		else {
			ll i, c = 1;
			for (i = 2; i * i <= n; i++) {
				if (n % i == 0) {
					c = max(c, i);
					c = max(c, n / i);
				}
			}
			cout << c << " " << n - c << "\n";
		}
	}
	return 0;
}