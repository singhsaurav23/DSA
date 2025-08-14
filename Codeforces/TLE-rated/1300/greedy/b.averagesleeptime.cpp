//sliding window
//precompute each index how many it will add

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double

int main() {
    ll i, k, n;
    cin >> n >> k;
    vector<ll> v(n);
    for (i = 0; i < n; i++) cin >> v[i];
    ll ans = 0;
    ll c = 1;
    ll x = min(n - k + 1, k);
    bool f = true;
    for (i = 0; i < n; i++) {
        ans += (c * v[i]);
        //cout<<c<<" ";
        if (c == x) f = false;
        if (f) c++;
        else if (!f && ((n - i - 1) < x)) c--;
    }
    cout << fixed << setprecision(6) << ((dd)ans / (n - k + 1)) << endl;
    return 0;
}

//approach 2: easy
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double

int main() {
    ll i, k, n;
    cin >> n >> k;
    vector<ll> v(n);
    for (i = 0; i < n; i++) cin >> v[i];
    ll ans = 0, sum = 0;
    for (i = 0; i < k; i++) sum += v[i];
    ans = sum;
    ll j = 0;
    for (i = k; i < n; i++) {
        sum += v[i];
        sum -= v[j];
        ans += sum;
        j++;
    }
    cout << fixed << setprecision(6) << 1.0 * ((dd)ans / (n - k + 1)) << endl;
    return 0;
}


