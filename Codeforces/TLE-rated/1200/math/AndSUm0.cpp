//k bits and n elments for each bit should be 0 sho nC1* nC1* for each elemnts postion k from nelemnts choose 1 bit to 0..n*n*n..k times

#include <bits/stdc++.h>

using namespace std;

int n, k;
const int MOD = 1e9 + 7;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &k);
        long long ans = 1;
        for (int i = 0; i < k; i++) ans = (ans * n) % MOD;
        printf("%lld\n", ans);
    }
}