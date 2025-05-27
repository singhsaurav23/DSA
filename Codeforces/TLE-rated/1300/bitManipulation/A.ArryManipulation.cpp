/*
Problem: Elimination Operations on an Array
Given an array a of n integers, you can perform the following elimination operation with a parameter k (1 ≤ k ≤ n):

Choose k distinct indices 1 ≤ i₁ < i₂ < ... < iₖ ≤ n.

Compute x = a[i₁] & a[i₂] & ... & a[iₖ], where & is the bitwise AND.

Subtract x from each of a[i₁], a[i₂], ..., a[iₖ].

You can repeat this operation as many times as needed.

🧩 Goal:
Find all valid values of k such that it's possible to reduce all array elements to zero using a finite number of operations.

🧠 Key Observation
To reduce every element to 0, we need every bit position (0 to 30) in all elements to be eliminated eventually

Therefore, to eliminate bit b, we must choose k elements that all have bit b set.

So, if bit b appears in cnt[b] elements, we can eliminate it only when we process k elements at a time, and cnt[b] is divisible by k.

✅ Valid k Condition:
We want to find all k (from 1 to n) such that for every bit, the total number of times it's set across the array is divisible by k.

Main->

Bit-level Insight:
Each bit b (from 0 to 30) can only be removed via the AND operation if it's present in all k chosen elements.
coz k set bits and is k and k-k is 0 so make it zero if number of set bits is k divisble so so k sets can make it 0
eg: 1 1 1 and 1 -1 0 so k 3
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--) {
        ll n, i, j;
        cin >> n;
        vector<ll> v(n);
        unordered_map<ll, ll> mp;
        for (i = 0; i < n; i++) cin >> v[i];
        for (i = 0; i < 30; i++) {
            for (j = 0; j < n; j++) {
                if (((1 << i) & v[j]) != 0) mp[i]++;
            }
        }
        cout << 1 << " ";
        for (i = 2; i <= n; i++) {
            ll c = 0;
            for (j = 0; j < 30; j++) {
                if (mp[j] % i != 0) { c = 1; break; }
            }
            if (c == 0) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}