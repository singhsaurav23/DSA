// in order to have max mod till i maintain yh emap, if it is first time take it otherwise taake next if that is first time otherwise 0.
// insert 0 with numbers have frequency is 0.
/*
Given a sequence of positive integers, a positive integer is called a mode of the sequence if it occurs the maximum number of times that any positive integer occurs. For example, the mode of [2,2,3]
 is 2
. Any of 9
, 8
, or 7
 can be considered to be a mode of the sequence [9,9,8,8,7,7]
.

You gave UFO an array a
 of length n
. To thank you, UFO decides to construct another array b
 of length n
 such that ai
 is a mode of the sequence [b1,b2,…,bi]
 for all 1≤i≤n
.

However, UFO doesn't know how to construct array b
, so you must help her. Note that 1≤bi≤n
 must hold for your array for all 1≤i≤n
.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, i;
        cin >> n;
        vector<ll> v(n);
        vector<ll> mp(n + 1);
        set<ll> ss;
        for (i = 0; i < n; i++) {
            cin >> v[i];
            ss.insert(v[i]);
        }
        ll kk = 0;
        mp[kk++] = v[0];
        unordered_map<ll, ll> vv;
        vv[v[0]]++;
        ll ma = 1, c = 0, j;
        vector<ll> un;
        for (i = 1; i < n - 1; i++) {
            if (vv[v[i]] != 1) { mp[kk] = v[i]; vv[v[i]] = 1; }
            else {
                mp[kk] = v[i + 1];
                if (vv[v[i + 1]] == 1) {
                    mp[kk] = 0;
                    c++;
                }
                else vv[v[i + 1]] = 1;
            }
            kk++;
            int xx = ss.size();
            ss.insert(i);
            if (ss.size() - 1 == xx) un.push_back(i);
        }
        mp[n - 1] = v[n - 1];
        for (i = n - 1; i <= n; i++) {

            int yy = ss.size();
            ss.insert(i);
            if (ss.size() - 1 == yy) un.push_back(i);
        }

        j = 0;
        for (i = 0; i < n; i++) {
            if (mp[i] == 0) {
                mp[i] = un[j++];
            }
        }

        for (i = 0; i < n; i++) cout << mp[i] << " ";
        cout << endl;
    }
    return 0;
}