//Codeforces Round 983 (Div. 2)
// first try to find child of 1
// iterate through all potential parents and store them , ie, they are leaf
// tree will mostly be sorted in a single line branch for n ary tree
// rest nodes just try see who is the parent ,coz maintina px<=py where x<=y

#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n, i, j;
        cin >> n;
        vector<int> pa(n, 0);
        pa[1] = 0;
        int type = 0;
        int queries_count = 0;

        auto query = [&](int a, int b) {
            if (++queries_count > (2 * n - 6)) return -1;
            cout << "? ";
            cout << a << " " << b << endl;
            int res;
            cin >> res;
            return res;
        };

        auto answer = [&]() {
            cout << "! ";
            for (i = 1; i < n; i++) cout << pa[i] << " ";
            cout << endl;
            return 0;
        };

        j = 2;
        while (j < n && query(j, 1) == 1) j++;

        if (j < n) pa[j] = 1;
        i = 2;
        set<ll> parents;
        while (i < j) { parents.insert(i); i++; }



        for (i = j + 1; i < n; i++) {
            pa[i] = i - 1;
            vector<ll> er;
            for (auto& it : parents) {
                er.push_back(it);
                type = query(it, i);
                if (type == 0) {
                    pa[i] = it;
                    break;
                }
            }
            for (auto& it : er) parents.erase(it);
            if (pa[i] != i - 1) parents.insert(i - 1);
        }

        answer();
        parents.clear();
    }

    return 0;
}