
/*
* Codeforces Round 925 (Div. 3)
Let's consider a good pair.

Since (ai+aj)modx=0
, it follows that (aimodx+ajmodx)modx=0
, which implies that aimodx+ajmodx
 is either x
 or 0
. Therefore, for some j
, this holds true if aimodx=(x−ajmodx)modx
.

Since (ai−aj)mody=0
, it follows that aimody−ajmody=0
, which implies that aimody=ajmody
.

Thus, for some fixed aj
, all ai
 will fit the following criteria:

i<j
;
aimodx=(x−ajmodx)modx
;
aimody=ajmody
.
We will iterate through j
 from left to right and maintain the count of elements with specific pairs ⟨aimodx,aimody⟩
 using a map on the prefix.
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, n, x, y, z;
        cin >> n >> x >> y;
        map<pair<ll, ll>, ll> mp;
        cin >> z;
        mp[{z% x, z% y}]++;
        ll cnt = 0;
        for (i = 1; i < n; i++) {
            cin >> z;
            ll xx = (x - z % x) % x;
            ll yy = z % y;
            if (mp[{xx, yy}] >= 1) cnt += mp[{xx, yy}];
            mp[{z% x, z% y}]++;
        }
        cout << cnt << endl;
    }
    return 0;
}