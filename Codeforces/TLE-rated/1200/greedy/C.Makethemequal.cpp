#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, i;
        cin >> n; char c; cin >> c;
        string s; cin >> s;
        ll pre = -1, pre1 = -1;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                pre = i + 1;
            }
            else {
                pre1 = i + 1;
            }
        }
        if (pre1 == -1) cout << 0 << endl;
        else {
            if (pre == -1 || pre == 1) {
                cout << 2 << endl;
                cout << n << " " << n - 1 << "\n";
            }
            else {
                ll flag = 0;
                for (i = pre - 1; i < s.size(); i += pre) {
                    if (s[i] != c) { flag = -1; break; }
                }
                if (flag == 0) {
                    cout << 1 << "\n";
                    cout << pre << endl;
                }
                else {
                    cout << 2 << endl;
                    cout << n << " " << n - 1 << endl;
                }
            }
        }
    }
    return 0;
}