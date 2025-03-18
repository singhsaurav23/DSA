/*Hi everyone,
I recently gone through Amazon interview process and was asked a question. I was not able to come with optimal approach during the interview and also didn't find any such question on internet.

Question:
Find the only non-repeating element where every other element repeat twice and duplicates are always together.
[5,5,3,3,1,2,2]

My Approach - XOR OR BS */

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i;
    vector<int> v(n);
    for (i = 0; i < n; i++) cin >> v[i];

    int ans = -1, l = 0, r = n - 1;
    if (v[0] != v[1]) cout << v[0];
    else if (v[n - 1] != v[n - 2]) cout << v[n - 1];
    else {
        while (l <= r) {
            int m = l + (r - l) / 2;
            if ((m - 1) >= 0 && (m + 1) < n && v[m] != v[m - 1] && v[m] != v[m + 1]) {
                ans = m;
                break;
            }
            else if (m % 2 == 0 && (m + 1) < n && v[m] == v[m + 1]) {
                l = m + 2;
            }

            else if (m % 2 == 0 && (m - 1) >= 0 && v[m] == v[m - 1]) {
                r = m - 2;
            }

            else if (m % 2 != 0 && (m + 1) < n && v[m] == v[m + 1]) {
                r = m - 1;
            }

            else if (m % 2 != 0 && (m - 1) >= 0 && v[m] == v[m - 1]) {
                l = m + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}