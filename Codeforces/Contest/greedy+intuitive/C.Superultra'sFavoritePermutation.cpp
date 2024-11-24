#include <bits/stdc++.h>
using namespace std;
#define ll int

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, i;
        cin >> n;
        if (n < 5) {
            cout << -1 << endl;
        }
        else {
            // Print even numbers except 4
            for (i = 2; i <= n; i += 2) {
                if (i == 4) continue;
                cout << i << " ";
            }
            cout << 4 << " " << 5 << " "; // Include 4 and 5

            // Print odd numbers except 5
            for (i = 1; i <= n; i += 2) {
                if (i == 5) continue;
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}