// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long


// int main() {
//     ll n,i;
//     cin>>n;
//     vector<ll> data(n);
//     for(i=0;i<n;i++) cin>>data[i];
//     vector<pair<ll,ll>> data_pair(n);
//     for(i=0;i<n;i++){
//         data_pair[i].first=data[i];
//         data_pair[i].second=i+1;
//     }
//     sort(data_pair.begin(),data_pair.end());
//     for(i=0;i<n;i++){
//         data[i]=data_pair[i].second;
//         cout<<data[i]<<" ";
//     }

// return 0;
// this is a sorting question aksed whhich permuattaion will give max answer so sorting is the key
// }

//question 2:Given orders and shifts, return pending orders at the end of each shift.
/*

input: n = 5, orderProcessingTime = [2, 4, 5, 1, 1], m = 5, shiftDuration = [1, 5, 1, 5, 2]
output : [5, 3, 3, 1, 0]

so for ecah iteration of m tell remianing jobs ... shift will start doing job from first to last jobs for each m and take values greater than 0;

if an order is not fully processed by the end of a shift, it will be continued in the next shift.
input : n = 5, orderProcessingTime = [1, 2, 4, 1, 2], m = 5, shiftDuration = [3, 10, 1, 1, 1]
output : [3, 0, 4, 4, 3]
https://leetcode.com/discuss/interview-question/6460397/Amazon-or-SDE-II-or-OA
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n, m, i;
    cin >> n;
    cin >> m;
    vector<ll> shift_time(m), process_time(n);
    for (i = 0; i < n; i++) cin >> process_time[i];
    for (i = 0; i < m; i++) cin >> shift_time[i];

    for (i = 1; i < n; i++) process_time[i] += process_time[i - 1];
    ll s = 0;
    vector<ll> ans;
    for (i = 0; i < m; i++) {
        ll x = shift_time[i] + s;
        auto j = lower_bound(process_time.begin(), process_time.end(), x);
        if (j == process_time.end()) { ans.push_back(0); s = 0; }
        else {
            ll xx = j - process_time.begin();
            if (process_time[xx] == x) ans.push_back(n - xx - 1);
            else ans.push_back(n - xx);
            if (xx == n - 1 && process_time[xx] == x) s = 0;
            else s = x;
        }
    }
    for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}

