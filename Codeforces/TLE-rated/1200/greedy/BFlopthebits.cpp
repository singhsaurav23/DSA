#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, i;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		vector<ll> pref(n, 0);
		for (i = 0; i < n; i++) {
			if (s1[i] == '0') pref[i] = 1;
		}
		for (i = 1; i < n; i++) pref[i] += pref[i - 1];
		ll f = 0;
		for (i = n - 1; i >= 0; i--) {
			if (f == 0) {
				if (s1[i] != s2[i]) {
					if (pref[i] == ((i + 1) - pref[i]))
						f = 1;
					else {
						f = -1; break;
					}
				}
			}
			else {
				if (s1[i] == s2[i]) {
					if (pref[i] == ((i + 1) - pref[i]))
						f = 0;
					else {
						f = -1; break;
					}
				}
			}
		}
		if (f == -1) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}