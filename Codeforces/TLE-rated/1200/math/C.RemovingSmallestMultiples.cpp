/*
Idea: Sieve: start with smallest number go to all multiples and take that cost to flip the bit
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, n, j;
        cin >> n;
        string s;
        cin >> s;
        vector<char> v(n);
        for (i = 0; i < n; i++) {
            v[i] = '1';
        }
        ll cost = 0;
        for (i = 1; i <= n; i++) {
            if (s[i - 1] == '0') {
                for (j = i; j <= n; j += i) {
                    if (s[j - 1] == '1') break;
                    if (v[j - 1] == '1') {
                        cost += i;
                        v[j - 1] = '0';
                    }
                }
            }
        }
        cout << cost << endl;
    }
}