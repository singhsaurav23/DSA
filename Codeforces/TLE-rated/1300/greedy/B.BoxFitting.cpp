//power of 2 sums can get any number you want so if you have width always take maximum valaibale number which will make of powrr of 2 coz only powwer of 2 numbers are there
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, w, i, x;
		cin >> n >> w;
		multiset<ll> st;
		for (i = 0; i < n; i++) { cin >> x; st.insert(x); }
		ll h = 1, ww = w;
		while (st.size() > 0) {
			auto it = st.upper_bound(ww);
			if (it == st.begin()) {
				ww = w;
				h++;
				continue;
			}
			it--;
			ww -= *it;
			st.erase(it);
		}
		cout << h << endl;
	}
	return 0;
}