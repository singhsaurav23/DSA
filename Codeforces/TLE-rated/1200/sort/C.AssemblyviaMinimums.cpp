//Codeforces Round 891 (Div. 3)
//move from n-1, n-2 coz each number smaller will be i-1(i=n....1) times
//as n-1+n-2+....+1=(n*(n-1))/2

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int m = n * (n - 1) / 2, b[m];
        for (int i = 0; i < m; i++)cin >> b[i];
        sort(b, b + m);
        for (int i = 0; i < m; i += --n)cout << b[i] << ' ';
        cout << "1000000000\n";
    }
}