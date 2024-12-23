//spiral take minimum 0s or 1s

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll k, j, n, i, m;
        cin >> n;
        vector<string> v(n);
        for (i = 0; i < n; i++) cin >> v[i];
        i = 0, j = 0;

        ll ans = 0;

        while (j < ((n + 1) / 2)) {
            i = j;
            while (i < (n - j - 1)) {

                ll c1 = 0, c0 = 0;
                //first
                m = i;  k = j;
                if (v[m][k] == '1') c1++;
                else c0++;
                //second
                m = j; k = n - i - 1;
                if (v[m][k] == '1') c1++;
                else c0++;
                //third
                m = n - i - 1; k = n - j - 1;
                if (v[m][k] == '1') c1++;
                else c0++;
                //fourth
                m = n - j - 1; k = i;
                if (v[m][k] == '1') c1++;
                else c0++;

                ans += min(c1, c0);
                //cout<<min(c1,c0)<<" ";
                i++;
            }
            j++;
        }
        cout << ans << endl;
    }
}