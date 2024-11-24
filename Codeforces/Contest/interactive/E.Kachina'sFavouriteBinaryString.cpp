//Codeforces Round 988 (Div. 3)
// check from 1 to i(2....n) ifcomes x subsequnece then till x indices everything will be 0 others will be 1
// if 01 never comes >impossisble
// if cnt prv == same cur cnt then 0 else 1 update prev cnt

#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, i, j;
        cin >> n;
        vector<char> v(n);
        int queries_count = 0;
        auto query = [&](int l, int r) {
            if (++queries_count > n) return -1;
            cout << "? ";
            cout << l << " " << r << endl;
            int res;
            cin >> res;
            return res;
        };

        auto answer = [&]() {
            cout << "! ";
            for (i = 0; i < n; i++) cout << v[i];
            cout << endl;
            return 0;
        };
        ll cnt = 0;
        for (i = 2; i <= n; i++) {
            ll x = query(1, i);
            if (cnt == 0 && x == 0) continue;
            else if (cnt == 0 && x) {
                cnt = x;
                v[i - 1] = '1';
                ll y = cnt;
                j = i - 2;
                while (y--) {
                    v[j] = '0';
                    j--;
                }
                while (j >= 0) {
                    v[j] = '1';
                    j--;
                }
            }
            else {
                if (cnt == x) {
                    v[i - 1] = '0';

                }
                else {
                    v[i - 1] = '1';
                    cnt = x;
                }
            }
        }
        if (cnt == 0) {
            cout << "! IMPOSSIBLE\n";
        }
        else {
            answer();
        }
    }

    return 0;
}