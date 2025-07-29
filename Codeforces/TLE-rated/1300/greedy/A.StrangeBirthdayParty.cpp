//easy sorting assign greater index to the cost first then cash
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m, i;
		cin >> n >> m;
		vector<ll> v(n), c(m);
		for (i = 0; i < n; i++) cin >> v[i];
		for (i = 0; i < m; i++) cin >> c[i];
		sort(v.begin(), v.end(), greater<ll>());
		ll s = 0, j = 0;

		for (i = 0; i < n; i++) {
			s += min(c[v[i] - 1], c[j]);
			if (c[j] < c[v[i] - 1]) {
				j++;
			}
		}
		cout << s << endl;
	}
	return 0;
}