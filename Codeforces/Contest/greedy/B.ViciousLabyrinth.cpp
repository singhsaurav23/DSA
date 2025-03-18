//check for n=odd and n-even how can you minimize such that direction is minimum
/*
Understanding the Problem Statement
You have
𝑛
n cells in a labyrinth, and each cell
𝑖
i has a person in it. The distance of cell
𝑖
i from the exit is
𝑛
−
𝑖
n−i. The exit is at cell
𝑛
n.

You need to install a teleporter in each cell that transports the person in that cell to another cell
𝑎
𝑖
a
i
​
  (where
𝑖
≠
𝑎
𝑖
i

=a
i
​
 , meaning no self-loops).

After
𝑘
k teleportations, you want to minimize the sum of distances of all people from the exit.

What does "direction" mean?
The teleporters you install in each cell define a mapping of each cell to another cell. This mapping is called "direction" because it determines where each person moves in every teleportation step.

For example, if:

𝑎
=
[
2
,
3
,
2
]
a=[2,3,2]
Cell 1 teleports to cell 2.
Cell 2 teleports to cell 3.
Cell 3 teleports to cell 2.
This means all individuals follow the same movement pattern in every teleportation step.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, j, i, k;
        cin >> n >> k;
        vector<ll> v(n);
        if (k % 2 == 0) {
            for (i = 0; i < n - 2; i++) cout << n - 1 << " ";
            cout << n << " " << n - 1 << "\n";
        }
        else {
            for (i = 0; i < n - 1; i++) cout << n << " ";
            cout << n - 1 << "\n";
        }
    }
    return 0;
}