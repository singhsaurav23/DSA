//make all numbers less than m using modulo and making all as remianders 

#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, m, i;
		cin >> n >> m;
		vector<ll> v(n);
		for (i = 0; i < n; i++) cin >> v[i];
		map <ll, ll> mp;

		for (i = 0; i < n; i++) { v[i] = v[i] % m; mp[v[i]]++; }

		ll ans = 0;
		for (auto it : mp) {
			ll x = it.first;
			ll y = it.second;
			if (y == -1) continue;
			if (x == 0) {
				ans++;
			}
			else if ((m - x) == x) {
				ans++;
			}
			else {
				ll z = 0;
				if (mp.find(m - x) != mp.end()) z = mp[m - x];
				mp[m - x] = -1;
				ll mi = min(z, y);
				if (mi == z) {
					if (y > mi) ans += y - (mi + 1);
				}
				else {
					if (z > mi) ans += z - (mi + 1);
				}

				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}