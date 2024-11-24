#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n,b,c;
        cin>>n>>b>>c;
        if(n==1){
            if(c==0) cout<<0;
            else cout<<1;
        }
        else if(b==0){
            if(n>(c+2)) cout<<-1;
            else if(c>(n-1)) cout<<n;
            else cout<<n-1;
        }
        else if(b==1) cout<<min(n,c);
        else{
           ll y=n-1-c+b;
        
           if((n-1)<c) cout<<n;
           else{
            ll x=y/b;
           
            if(y%b==0){
             
            ll aa=c+(x-1)*b;
            if(aa<=n-1) cout<<n-x;
            
            }else{
                ll aa=c+(x-1)*b;
                ll bb=c+(x)*b;
             
            if(aa<=n-1&&bb>(n-1)) cout<<n-x;
            else if(bb<=n-1) cout<<n-x-1;
            else if(aa>(n-1)) cout<<n-x+1;
            }
           }
        }
        cout<<endl;
    }
    return 0;
}