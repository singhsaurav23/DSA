//codeforces 1002 div2 maintain suffxes of 1s for every queu to minatin the order the customers and to find mex served
// use mutiset to tune your answer so that each contributing to which value max present from 1 to m

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll i, j, n;
		cin >> n;
		vector<vector<ll>> v(n, vector<ll>(n));
		vector<ll> suf(n, 0);
		for (i = 0; i < n; i++) {

			for (j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}

		for (i = 0; i < n; i++) {
			for (j = n - 1; j >= 0; j--) {
				if (v[i][j] == 1) suf[i]++;
				else break;
			}
		}
		multiset<ll> st;
		for (i = 0; i < n; i++) st.insert(suf[i]);
		ll ans = 1;
		for (auto it : st) {
			if (it >= ans) ans++;
		}

		if (ans > n) ans = n;
		cout << ans << endl;
	}
	return 0;
}