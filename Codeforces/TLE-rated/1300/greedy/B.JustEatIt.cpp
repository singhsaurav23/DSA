//if total sum is s
// you want to find some segment sum not total as x
// os inorder to x>=s porefix or suffic should be some <=0
// then only entire sum is smaller than some segment in middlle
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ll t;
	cin >> t;
	while (t--) {
		ll n, i, s = 0, c = 0;
		cin >> n;
		vector<ll> v(n);
		for (i = 0; i < n; i++) cin >> v[i];

		for (i = 0; i < n; i++) {
			s += v[i];
			if (s <= 0) { c = 1; break; }
		}
		if (c == 1) cout << "NO\n";
		else {
			s = 0;
			for (i = n - 1; i >= 0; i--) {
				s += v[i];
				if (s <= 0) { c = 1; break; }
			}
			if (c == 1) cout << "NO\n";
			else cout << "YES\n";
		}
	}
	return 0;
}