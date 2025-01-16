#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, i, j = 0, prev;
		cin >> n;
		vector<ll> v(n);
		set<ll> s;
		for (i = 0; i < n; i++) { cin >> v[i]; s.insert(v[i]); }
		if (s.size() == 1) cout << "NO\n";
		else {
			i = 0; cout << "YES\n";
			for (j = 0; j < n; j++) {
				if (i == j) continue;
				if (v[i] == v[j]) continue;
				cout << i + 1 << " " << j + 1 << "\n";
				prev = j + 1;
				v[j] = -1;

			}
			for (i = 1; i < n; i++) {
				if (v[i] != -1) cout << prev << " " << i + 1 << "\n";
			}

	}
	return 0;
}