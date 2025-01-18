//modulus use, pattern observe for odd numbers how they mov forward n/2 chnage for n times and remainder increasing by 1.1..1..n/2 times then 2....n/2 times for whole n times when 
// n.n-1.n-2....1
// 1 2 3 ......
// summation will (n+1)%n =1....(n-1+2)%n=1.....then after n/2 times it will 2.2.2. remainder
// also (a+b)%n=d then b=(d-a+n)%n where if 0 the naser is n else (d-a+n)%n

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		if (n % 2 == 0) {
			if (k % n == 0) cout << n << "\n";
			else cout << k % n << "\n";
		}
		else {
			ll c = n / 2;
			if (((k + c - 1) / c) % n == 0) {
				ll a;
				if (k % n == 0) a = 1;
				else a = n - k % n + 1;
				cout << n - a << endl;
			}
			else {
				ll d = ((k + c - 1) / c) % n;
				ll a;
				if (k % n == 0) a = 1;
				else a = n - k % n + 1;
				if ((d - a + n) % n == 0) cout << n << endl;
				else cout << (d - a + n) % n << endl;
			}
		}
	}
	return 0;
}