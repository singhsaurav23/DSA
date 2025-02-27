//array manipulation of adding and remove first elment and mainatining order nlogn
// question https://askfilo.com/user-question-answers-smart-solutions/2-code-question-2-as-an-aspiring-developer-at-amazon-you-are-3232373137383131
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, m, i;
    cin >> n;
    cin >> m;
    vector<ll> v(n), q(m);
    for (i = 0; i < n; i++) cin >> v[i];
    for (i = 0; i < m; i++) cin >> q[i];
    // vector<pair<ll,ll>> vp(n);
    multiset<pair<ll, ll>> st;
    for (i = 0; i < n; i++) {
        st.insert({ v[i],i });
    }
    ll c = n;

    //   sort(vp.begin(),vp.end(),comp);
    //   ll c=n;
    for (i = 0; i < m; i++) {
        ll x = q[i];
        if (x < 0) {
            auto it = st.lower_bound({ abs(x), INT_MIN });  // INT_MIN ensures we get the first matching key
            if (it != st.end() && it->first == abs(x))
                st.erase(it);
        }
        else {
            st.insert({ x,c++ });
        }
    }
    vector<ll> ans;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (auto it : st) {
        pq.push({ it.second,it.first });
    }
    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}