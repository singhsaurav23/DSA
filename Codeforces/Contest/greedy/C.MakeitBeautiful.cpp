//think in bits
// smallest num greater than ele is where smallest lsvb bit 0 to 1 -> 1<<i 
//pick smallest operation and decrease k


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

template <typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using oms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// read question properly
// don't forget newlines!!!!!!
// take care about cin >> t;
// comment the optimization before debugging
// ALWAYS USE FIXED << SETPRECISION WHILE OUTPUTTING FLOATS

void solve()
{
    ll n,k;
    cin >> n >> k;
    ia(a,n);
    set<pair<ll,ll>> s;
    f(i,n) {
        ll j = 0;
        while((1LL<<j) & a[i]) {
            j++;
        }
        s.insert(mp(1LL<<j, i));
    }
    ll ans = 0;
    f(i,n) {
        ans += __builtin_popcountll(a[i]);
    }
    while(k > 0) {
        if(s.begin()->first <= k) {
            k -= s.begin()->first;
            a[s.begin()->second] |= s.begin()->first;
            ans++;
            ll idx = s.begin()->second;
            s.erase(s.begin());

            ll j = 0;
            while((1LL<<j) & a[idx]) {
                j++;
            }
            s.insert(mp(1LL<<j, idx));
        }
        else break;
    }

    cout << ans << nline;
}

int main()
{
#ifdef PRADY
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t T = clock();
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

#ifdef PRADY
    cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
#endif
    return 0;
}