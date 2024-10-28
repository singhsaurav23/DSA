//Educational Codeforces Round 170 (Rated for Div. 2)
//D. Attribute Checks
// for each 0s coming try to incr strength or intelligence using total and maintain sorted strength & intelligence between 0s for biinary search to find how many less and big

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n, m, i, j;
	cin >> n >> m;
	vector<int> v(n);
	vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
	dp[0][0] = 0;
	vector<int> a, b;
	int tot = 0;
	for (i = 0; i < n; i++) cin >> v[i];
	for (i = 0; i < n; i++) {

		if (v[i] == 0) {

			sort(a.begin(), a.end());
			sort(b.begin(), b.end());

			tot++;
			for (j = 0; j <= tot; j++) {
				//in
				if (j != 0) {
					int c1 = j - 1, c2 = tot - j;
					int val = (upper_bound(a.begin(), a.end(), c2) - a.begin()) + (upper_bound(b.begin(), b.end(), c1) - b.begin());
					dp[tot][j] = max(dp[tot][j], dp[tot - 1][j - 1] + val);
				}
				if (j < tot) {
					int c1 = j, c2 = tot - j - 1;
					int val = (upper_bound(a.begin(), a.end(), c2) - a.begin()) + (upper_bound(b.begin(), b.end(), c1) - b.begin());
					dp[tot][j] = max(dp[tot][j], dp[tot - 1][j] + val);
				}
			}
			a.clear();
			b.clear();

		}
		else {
			if (v[i] < 0) a.push_back(abs(v[i]));
			else b.push_back(v[i]);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ans = 0;
	for (j = 0; j <= m; j++) {
		int c1 = j, c2 = m - j;
		int val = (upper_bound(a.begin(), a.end(), c2) - a.begin()) +
			(upper_bound(b.begin(), b.end(), c1) - b.begin());
		ans = max(ans, dp[m][j] + val);
	}
	cout << ans << endl;

	return 0;
}