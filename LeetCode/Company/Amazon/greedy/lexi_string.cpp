/*
Code Question 2
ALL


The team at an Amazon warehouse is given a task to optimize the packing of a set of boxes with different IDs. Each box is labeled with an ID, and these boxes are currently arranged in a single row from left to right, where the id of the ith box is represented by the string sid consisting of digits from 0 to 9 inclusive. To make the packing more efficient, the team can perform the following operation any (possibly zero) number of times:


• Choose an index i and remove the digit s_idf. Then insert the box with ID min(s_idfi] + 1, 9) on any position (at the beginning, at the end, or in between any two adjacent boxes) in the row.
Given a string s_ id, find the lexicographically minimal string of boxes using these operations.
Note : A string X is lexicographically smaller than a string Y of the same length if and only if in the first position where X and Y differ, the string X has a smaller digit than the corresponding digit in Y.


Example
Given, s_id = "26547".

Delete 5 and insert 6 in the 4th position of the string

Delete 6 from the 2nd plastion and insert 7 in the 4th position of the string
7
Hence, the string returned is "24677".It can be proved that this is the lexicographically minimal string possible.


Function Description


Complete the function getMinimumString in the editor below.getMinimumString has the following parameter :


string s_id : the ID of the boxes


Returns


string.the lexicographically minimal string


Constraints


1≤ / 5id | = 2 * 105
﻿﻿s_id consists of only digits from 0 to 9. Note that s_id is just a string consisting of digits, so leading zeros are allowed.
﻿﻿Input Format For Custom Testing
﻿﻿Sample Case 0
Sample Input For Custom Testing


STDIN


FUNCTION


04829


s_id = 04829"


Sample Output


02599
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    string s;
    cin >> s;
    ll n = s.size(), i;
    multiset<ll> st;
    st.insert((s[n - 1] - '0'));
    char c = s[n - 1];
    for (i = n - 2; i >= 0; i--) {
        if (s[i] <= c) { st.insert(s[i] - '0'); c = s[i]; }
        else st.insert((s[i] - '0') + 1);
    }
    string ss = "";
    for (auto it : st) cout << it << " ";
    // for(auto it:ss) cout<<it<<" ";
    return 0;
}

string solve(const string& s) {
    const int n = (int)s.size();
    vector last(10, -1), cnt(10, 0);
    for (int i = 0; i < n; ++i)
        last[s[i] - '0'] = i;
    string ret; ret.reserve(n);
    int left = 0;
    for (int i = 0; i <= 9; ++i) {
        const int m = last[i];
        while (left <= m)
            if (const int j = s[left++] - '0'; i == j)
                cnt[i]++;
            else
                cnt[min(j + 1, 9)]++;
        const auto c = char(i + '0');
        for (int j = cnt[i]; j--;)
            ret.push_back(c);
    }
    return ret;
}