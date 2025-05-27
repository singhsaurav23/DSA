//binary search on 1 2 3 4 3 2 1... this kind of data
//Educational Codeforces Round 117 (Rated for Div. 2)

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll k, x;
        cin >> k >> x;
        ll n = 2 * k - 1;

        ll l = 1, r = k, prev = 0, ans = 1;
        while (l <= r) {
            ll m = l + (r - l) / 2;
            ll xx = m * (m + 1) / 2;
            if (xx <= x) {
                ans = m;
                prev = ((ans - 1) * (ans)) / 2;

                l = m + 1;
            }
            else r = m - 1;
        }


        //ll cc=ans;
        ll mm = (ans * (ans + 1)) / 2;
        if (mm == x) cout << ans << endl;
        else if (ans == k) {
            l = 1, r = k - 1; ll ts = (r * (r + 1)) / 2;
            ll ans1 = r, ss = mm + (ts - ((ans1 * (ans1 - 1)) / 2));

            while (l <= r) {
                ll m = l + (r - l) / 2;
                ll xx = m * (m - 1) / 2;
                ll yy = ts - xx;
                if ((yy + mm) <= x) {
                    ans1 = m;
                    ss = yy + mm;
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            ll next = mm + (ts - (((ans1 - 2) * (ans1 - 1)) / 2));
            if (ans == 1) cout << 1 << endl;
            else if (x<next && x>ss) cout << ans + k - ans1 + 1 << endl;
            else cout << ans + k - ans1 << endl;
        }
        else {

            ll next = ((ans + 1) * (ans + 2)) / 2;
            if (x<next && x>mm) cout << ans + 1 << endl;
            else cout << ans << endl;

        }
        //cout<<ans<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

long long get(int x) {
    return x * 1ll * (x + 1) / 2;
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) {
        int k;
        long long x;
        cin >> k >> x;
        long long l = 1, r = 2 * k - 1;
        long long res = 2 * k - 1;
        bool over = false;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid >= k) {
                over = (get(k) + get(k - 1) - get(2 * k - 1 - mid) >= x);
            }
            else {
                over = (get(mid) >= x);
            }
            if (over) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        cout << res << endl;
    }

    return 0;
}