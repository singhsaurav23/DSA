//2pointers sort enter and exit

// if current sorted in enter and it's exit i smaller than max(previous entered exit cars)
//max(exit of previous cars is gretaer than current exit so this car must be fined

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

	ll n, i, z, ma = 0, c = 0;
	cin >> n;
	vector<ll> st(n), en(n + 1);
	for (i = 0; i < n; i++) cin >> st[i];
	for (i = 0; i < n; i++) { cin >> z; en[z] = i + 1; }
	for (i = 0; i < n; i++) {
		ma = max(en[st[i]], ma);
		if (i > 0 && ma > en[st[i]]) c++;
	}
	cout << c << endl;
	return 0;
}