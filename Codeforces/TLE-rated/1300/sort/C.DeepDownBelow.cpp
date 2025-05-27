// inequality uestion
/*
* x>ai,1
 ;
x+1>ai,2
;
x+2>ai,3
;
...
x+(ki−1)>ai,ki
.
Let bi=max(ai,1,ai,2−1,ai,3−2,…,ai,ki−(ki−1))
. The system of inequalities above is equivalent to a single inequality: x>bi
.

Thus, the hero can enter cave i
 with power x
 if and only if x>bi
, and the hero's power will increase by ki
.

Armed with this knowledge, can we determine the best order to visit the caves for the hero?

It turns out it's always best to enter the caves in non-decreasing order of bi
. Indeed, if the hero can enter cave i
, he should always do that because entering a cave never makes things worse. If the hero enters a cave with greater b
 right before a cave with smaller b
, he might enter these caves in reverse order as well.

Let's sort the caves accordingly and assume b1≤b2≤…≤bn
. What is the smallest power the hero can start the level with?

We can use the same reasoning that we used for a single cave.

Suppose the hero starts the level with power x
. To enter the first cave, x
 has to be greater than b1
. After that, the hero's power will increase to x+k1
, and to enter the second cave, x+k1
 has to be greater than b2
. Continuing this reasoning, we can write down n
 inequalities:

x>b1
;
x+k1>b2
;
x+k1+k2>b3
;
...
x+∑i=1n−1ki>bn
.
Let p=max(b1,b2−k1,b3−(k1+k2),…,bn−∑i=1n−1ki)
. The system of inequalities above is equivalent to a single inequality: x>p
. Thus, the answer to the problem is p+1
.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

static bool comp(pair<ll, ll>& a, pair<ll, ll>& b)
{
    return a.first < b.first;
    if (a.first == b.first) return a.second < b.second;
}
int main()
{
    ll t;
    cin >> t;
    while (t--) {
        ll n, i, j, k;
        cin >> n;
        vector<pair<ll, ll>> v(n);
        for (i = 0; i < n; i++) {
            cin >> k;
            ll x;
            ll ma = -1;

            for (j = 0; j < k; j++) {
                cin >> x;
                ma = max(ma, x - j);
            }
            v[i] = { ma,k };

        }
        sort(v.begin(), v.end(), comp);
        ll ans = LONG_MIN, kk = 0;
        for (i = 0; i < n; i++) {
            ans = max(ans, v[i].first - kk);
            kk += v[i].second;
        }
        cout << ans + 1 << endl;

    }
    return 0;
}