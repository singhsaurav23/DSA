#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s;
    cin >> s;
    ll i, n = s.size();
    for (i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            if (i == n - 1 && s[i - 1] != 'z') s[i] = s[i - 1] + 1;
            else if (i == n - 1 && s[i - 1] == 'z') s[i] = 'y';
            else {
                if (s[i + 1] != 'z' && s[i - 1] != 'z') s[i] = 'z';
                else if (s[i + 1] != 'y' && s[i - 1] != 'y') s[i] = 'y';
                else if (s[i + 1] != 'x' && s[i - 1] != 'x') s[i] = 'x';
            }
        }
    }
    cout << s << endl;
    return 0;
}