#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll i, n, j, c = 0;
		cin >> n;
		for (i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				n = n / i;
				break;
			}
		}

		for (j = i + 1; j * j <= n; j++) {
			if (n % j == 0) {
				ll y = n / j;
				if (y != i && y != j) {
					cout << "YES\n";
					cout << i << " " << j << " " << y << "\n";
					c = 1; break;
				}
			}
		}

		if (c == 0) cout << "NO\n";
	}
	return 0;
}