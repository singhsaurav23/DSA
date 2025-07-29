//all number sunqiue and think on number line if two numbers are there what if the thirs number between them or before the range or after range, what should you do

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, i;
		cin >> n;
		vector<ll> v(n);
		for (i = 0; i < n; i++) cin >> v[i];
		vector<ll> ans(n);
		ans[0] = v[0];
		ans[1] = v[1];
		ll j = 1;
		for (i = 2; i < n; i++) {
			if (v[i] > ans[j] && ans[j - 1] < ans[j]) ans[j] = v[i];
			else if (v[i] > ans[j] && ans[j - 1] > ans[j]) ans[++j] = v[i];
			else if (v[i] < ans[j] && ans[j - 1] < ans[j]) ans[++j] = v[i];
			else if (v[i]<ans[j] && ans[j - 1]>ans[j]) ans[j] = v[i];
		}
		cout << j + 1 << "\n";
		for (i = 0; i <= j; i++) cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}