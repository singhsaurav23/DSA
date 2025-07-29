
//pattern question draw n=1,2,3,4,5 and visualize odd even pattern from drawing and values

#incldue<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<bool> vb;
#define pb push_back 
#define vpl vector<pair<ll,ll>>
#define vpls vector<pair<char,ll>>
#define pl pair<ll,ll>
#define sl set<ll> 
#define ump unordered_map<ll,ll> 
#define umps unordered_map<char,ll>
#define map map<ll,ll> 
#define loop(x,n) for(ll x = 0; x < n; ++x)


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    if (n % 2 != 0) {
        ll x = n / 2 + 1;
        ll y = n / 2 + 2;
        cout << 2 * x * y << "\n";
    }
    else {
        ll x = (n / 2) + 1;
        ll y = pow(x, 2);
        cout << y << "\n";
    }
    return 0;
}