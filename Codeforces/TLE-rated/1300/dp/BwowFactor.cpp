// number of consecutive v's on left and right multiply to get for each o
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    string s;
    cin >> s;
    ll n = s.size(), i, c = 0;
    vector<ll> l(n, 0);
    for (i = 1; i < n; i++) {
        if (s[i] == s[i - 1] && s[i] == 'v') {
            c++;
        }
        l[i] = c;
    }
    c = 0;
    ll ans = 0;
    for (i = n - 2; i >= 0; i--) {
        if (s[i] == s[i + 1] && s[i] == 'v') c++;
        if (s[i] == 'o') {
            ans += (c * l[i]);
        }
    }
    cout << ans << endl;
    return 0;
}


//clevcer approach calculate left v's then store that in o's whenever right v take o's for left to calculate sum
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    ll a = 0, b = 0, c = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == 'o') {
            b += a;
        }
        else if (i > 0 && S[i - 1] == 'v') {
            a++;
            c += b;
        }
    }
    cout << c << endl;
}


