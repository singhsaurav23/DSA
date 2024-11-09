// Array Break
// find number of ways to make array b and c where b[i]+c[i]=v[i] and b is increasing and c is decreasing in nature


#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

ll breaks(ll i, vector<ll>& v, ll prev, vector<vector<int>>& dp) {
    if (i == v.size()) return 1;
    ll t = 0;
    if (dp[i][prev] != -1) return dp[i][prev];
    for (ll j = prev; j <= v[i]; j++) {
        if (j <= v[i]) {
            ll cur = v[i] - j;
            if (cur <= (v[i - 1] - prev)) {
                t = (t % mod + (breaks(i + 1, v, j, dp)) % mod) % mod;
            }
        }

        else break;
    }
    return dp[i][prev] = t;
}

int main() {
    ll n, i, ma = 0;
    cin >> n;
    vector<ll> v(n, 0);
    for (i = 0; i < n; i++) { cin >> v[i]; ma = max(v[i], ma); }
    vector<vector<int>> dp(n + 1, vector<int>(ma + 1, -1));
    cout << breaks(0, v, 0, dp) << endl;
    return 0;
}

//prefix sum maintain for finding ways start from right to left rightmost can have maximum v[i] as increasing order for b
//state=i->index and j<=v[i] is value of b

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(),v.end()


signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int n;
        cin >> n;
        vector v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector<vector> dp(n, vector(3001, 0));
        int sum = 0;
        for (int i = 0; i <= v[n - 1]; i++) {
            dp[n - 1][i] = 1;
            sum += dp[n - 1][i];
            dp[n - 1][i] = sum;
        }
        for (int i = n - 2; i >= 0; i--) {
            sum = 0;
            for (int j = 0; j <= 3000; j++) {
                int up = v[i + 1];
                int down = max(v[i + 1] - v[i] + j, j);
                if (down <= up) {
                    if (down != 0) {
                        dp[i][j] = dp[i + 1][up] - dp[i + 1][down - 1];
                    }
                    else {
                        dp[i][j] = dp[i + 1][up];
                    }
                }
                sum += dp[i][j];
                dp[i][j] = sum;
            }
        }
        cout << dp[0][3000] << endl;
    
    return 0;
}