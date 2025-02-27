// try maintianing level of initial value to survive at each cell, bottom up if >0 it will be 0 as , it will help to find minimum  negative it can go for upper cells. to finid minimum initial health.

class Solution {
public:
    int dun(int i, int j, vector<vector<int>>& dung, vector<vector<int>>& dp) {
        if (i == dung.size() - 1 && j == dung[0].size() - 1) {
            if (dung[i][j] < 0)
                return dung[i][j];
            else return 0;
        }

        if (i >= dung.size() || j >= dung[0].size()) return -9999;
        if (dp[i][j] != -99999) return dp[i][j];
        int x = dung[i][j] + dun(i + 1, j, dung, dp);
        int y = dung[i][j] + dun(i, j + 1, dung, dp);
        int z = max(x, y);
        if (z < 0) {
            dp[i][j] = z;
            return dp[i][j];
        }
        return 0;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -99999));
        int z = dun(0, 0, dungeon, dp);
        return abs(z) + 1;
        return 1;
    }
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& v) {
        int i, j, n = v.size(), m = v[0].size(), ans = INT_MAX;
        for (i = n - 1; i >= 0; i--) {
            for (j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) {
                    v[i][j] = min(0, v[i][j]);
                }
                else if (i == n - 1) {
                    v[i][j] = min(0, v[i][j + 1] + v[i][j]);
                }
                else if (j == m - 1) {
                    v[i][j] = min(0, v[i + 1][j] + v[i][j]);
                }
                else {
                    v[i][j] = min(0, v[i][j] + max(v[i + 1][j], v[i][j + 1]));
                }
            }
        }
        return abs(v[0][0]) + 1;
    }

};

//2nd question was to minimum artculation point such that left top is not reachable to bottom right atmost 2 answer minimum one cell to find if there any

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dx[4] = { 0,0,1,-1 };
ll dy[4] = { 1,-1,0,0 };

bool issafe(int i, int j, vector<vector<ll>>& v) {
    if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] == 0) return false;
    return true;
}

int c = 1;

void dfs(ll i, ll j, int ii, int jj, vector<vector<ll>>& v, vector<vector<ll>>& tin, vector<vector<ll>>& low) {
    // if(i==3&&j==1) cout<<v[i][j]<<" ";
    v[i][j] = 2;

    tin[i][j] = c++;
    low[i][j] = c++;
    //cout<<i<<" "<<j<<"\n";
    for (ll m = 0; m < 4; m++) {
        ll x = i + dx[m];
        ll y = j + dy[m];
        if (x == 0 && y == 0) continue;
        if (x == v.size() - 1 && y == v[0].size() - 1) continue;
        if (x == ii && y == jj) continue;
        //if(v[x][y]==0) continue;
        if (issafe(x, y, v)) {
            if (v[x][y] == 2) {
                low[i][j] = min(low[i][j], tin[x][y]);
            }
            else {

                dfs(x, y, i, j, v, tin, low);
                low[i][j] = min(low[i][j], low[x][y]);
                if (low[x][y] >= tin[i][j] && ii != -1 && jj != -1) cout << i << " " << j << "\n";

            }
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll i, j, n, m;
        cin >> n >> m;

        vector<vector<ll>> v(n, vector<ll>(m));
        vector<vector<ll>> tin(n, vector<ll>(m, -1));
        vector<vector<ll>> low(n, vector<ll>(m, -1));
        vector<ll> suf(n, 0);
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        //articulation points
        dfs(0, 0, -1, -1, v, tin, low);

    }
    return 0;
}