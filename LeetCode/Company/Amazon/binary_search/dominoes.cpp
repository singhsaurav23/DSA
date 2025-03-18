/*
Amazon Games has launched a new game involving dominoes. The game consists of n dominoes, each with a specific size denoted by the array domino. The "order" of the dominoes is defined as the length of the longest strictly increasing subsequence (LIS) of their sizes.

There is also an array remove that contains integers from 0 to n-1. In each move, the player can remove the domino specified by the remove array. The goal is to determine the maximum number of moves that can be made such that, after these removals, the order of the remaining dominoes is at least equal to a given integer min_order.

Example:
n = 6

domino = [1, 4, 4, 2, 5, 3]

remove = [2, 1, 4, 0, 5, 3]

min_order = 3

In this example, the player can remove dominoes in the order specified by remove. After each removal, the length of the LIS of the remaining dominoes should be at least min_order. The task is to find out the maximum number of such removals possible.

Ans = 3

Hints:* Longest Increasing Subsequcne , Binary Search*
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool LIS(ll m, vector<ll>& v, vector<ll>& r, ll k) {
    ll i, n = r.size();
    vector<ll> arr(n);
    for (i = 0; i < n; i++) arr[i] = v[i];
    for (i = 0; i <= m; i++) {
        arr[r[i]] = -1;
    }
    vector<int> ans;
    for (i = 0; i < n; i++) {
        if (arr[i] == -1) continue;
        if (ans.size() == 0) ans.push_back(arr[i]);
        else {
            auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
            if (it == ans.end()) ans.push_back(arr[i]);
            else ans[it - ans.begin()] = ans[i];
        }
    }
    if (ans.size() >= k) return true;
    else return false;
}

int main() {
    ll t;
    t = 1;
    while (t--) {
        ll n, i, k;
        cin >> n >> k;
        vector<ll> v(n), r(n);
        for (i = 0; i < n; i++) cin >> v[i];
        for (i = 0; i < n; i++) cin >> r[i];
        ll l = 0, rr = n - k - 1, ans = -1;
        while (l <= rr) {
            ll m = l + (rr - l) / 2;
            // cout<<m<<" ";
            if (LIS(m, v, r, k)) {
                ans = m;
                l = m + 1;
            }
            else rr = m - 1;
        }
        cout << n - ans - 1 << endl;
    }
    return 0;
}