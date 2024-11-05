/*Codeforces Round 983 (Div. 2)
* C. Trinity-> 2 pointers
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, i;
        cin >> n;
        vector<ll> a(n);
        for (i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        i = 0;
        ll l = 0, r, ans = n - 2;
        for (r = 2; r < n; r++) {
            while ((r - l) >= 2 && (a[l] + a[l + 1]) <= a[r]) l++;
            ans = min(ans, n - (r - l + 1));
        }
        cout << ans << endl;
    }
    return 0;
}
/*
Binary Serach->
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n,i;
        cin>>n;
        vector<ll> a(n);
        for(i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        i=0;
        ll l=0,r,ans=n-2;
    for(i=0;(i+1)<n;i++){
       l=i+1,r=n-1;
       ll ii=n-1;
       while(l<=r){
           ll m=l+(r-l)/2;
           if(a[m]<(a[i]+a[i+1])){
               ii=m;
               l=m+1;
           }else r=m-1;
       }
       ans=min(ans,n-(ii-i+1));
    }
    cout<<ans<<endl;
}
    return 0;
}


*/