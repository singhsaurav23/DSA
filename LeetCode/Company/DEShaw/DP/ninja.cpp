//Linear dp question
//jump from i to i+k
// initially c
// all a[i] are positive and negative integers
// can start from any index find maximum coins you have without going to jail
// c-a[i] or c+a[i]
/*TESTCASE - 3
10
- 5
20
2
0
O/P -> 30
TC- O(N) SC- O(N)
*/

#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;


int main() {
    ll n, k, c, i;
    cin >> n;
    vector<ll> v(n);
    for (i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> k >> c;
    vector<ll> dp(n, 0);
    ll ma = c;
    for (i = 0; i < n; i++) {
        ll cur = 0;
        if ((i - k) >= 0) cur = dp[i - k];
        dp[i] = max(dp[i], c + v[i]);
        dp[i] = max(dp[i], cur + v[i]);
        ma = max(ma, dp[i]);
    }
    cout << ma << endl;
    return 0;
}