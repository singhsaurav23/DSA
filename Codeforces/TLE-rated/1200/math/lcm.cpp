/*Codeforces Round 895 (Div. 3)
* D. Plus Minus Permutation
* Trick->number of x divisibility , y and lcm to manage maximum sum
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, i, x, y;
        cin >> n >> x >> y;
        ll l = ((x * y) / (__gcd(x, y)));
        ll a = n / x;
        ll b = n / y;
        ll o = n / l;
        //  cout<<a<<" "<<b<<" "<<o<<"\n";
        if (x == y) cout << 0 << endl;
        else if (a == o) {
            ll xx = b - o;
            cout << ((xx * (xx + 1)) / 2) * -1 << endl;
        }
        else {
            ll yy = n - a + o;
            ll xx = b - o;
            //  cout<<yy<<" "<<xx<<"\n";
            ll s = (n * (n + 1)) / 2 - (yy * (yy + 1)) / 2;
            cout << s - ((xx * (xx + 1)) / 2) << endl;
        }
    }
    return 0;
}
