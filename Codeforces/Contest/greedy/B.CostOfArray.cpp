// answer can be 1 ,2 or for n==k calculate... greedy thinking
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, k, i, j;
		cin >> n >> k;
		vector<ll> v(n);
		for (i = 0; i < n; i++) cin >> v[i];
		ll ans = 2;
		if (n == k) {
			ll y = 1;
			for (i = 1; i < n; i += 2) {
				if (v[i] != y) break;
				y++;
			}
			ans = y;
		}
		else {
			ans = 2;
			j = n - k + 2;
			i = 1;

			while (i < j) {
				//  cout<<v[i]<<" ";
				if (v[i] != 1) { ans = 1; break; }
				i++;
			}

		}
		cout << ans << endl;
	}
	return 0;
}