#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool dfs(int i, int j, int a, int b, string& s) {
    ll xx = 10000;
    while (xx--) {
        for (int k = 0; k < s.size(); k++) {
            if (s[k] == 'N') {
                j++;
            }
            else if (s[k] == 'E') {
                i++;
            }
            else if (s[k] == 'W') {
                i--;
            }
            else {
                j--;
            }
            if (i == a && j == b) return true;
        }
    }
    return false;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        string s; cin >> s;
        if ((dfs(0, 0, a, b, s))) {
            cout << "YES";
        }
        else cout << "NO";
        cout << endl;
    }
    return 0;
}