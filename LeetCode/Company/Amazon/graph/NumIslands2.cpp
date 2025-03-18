//after each operation what is number of connected componenets disjoint set union
//Number of Islands II

#include<bits/stdc++.h>
using namespace std;

int findPar(int y, vector<int>& par) {
    if (y == par[y]) return y;
    return par[y] = findPar(par[y], par);
}


void un(int x, int y, vector<int>& size, vector<int>& par) {
    int xx = findPar(x, par);
    int yy = findPar(y, par);
    if (xx == yy) return;
    if (size[xx] < size[yy]) {
        par[xx] = yy;
        size[yy] += size[xx];
    }
    else {
        par[yy] = xx;
        size[xx] += size[yy];
    }
}


int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    int i, j;
    vector<vector<int>> v(k, vector<int>(2, 0));
    for (i = 0; i < k; i++) cin >> v[i][0] >> v[i][1];

    vector<int> par(n * m, -1);
    vector<int> size(n * m, 1);

    for (i = 0; i < n * m; i++) par[i] = i;

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for (i = 0; i < k; i++) {
        int x = v[i][0] * m;
        int y = x + v[i][1];

        vis[v[i][0]][v[i][1]] = 1;
        ans++;

        for (j = 0; j < 4; j++) {
            int xx = dx[j] + v[i][0];
            int yy = dy[j] + v[i][1];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;

            if (vis[xx][yy] == 1) {
                if (findPar(y, par) != findPar(xx * m + yy, par)) {
                    ans--;
                    un(y, xx * m + yy, size, par);
                }
            }
        }
        cout << ans << " ";
    }

    cout << endl;
    for (i = 0; i < n * m; i++) cout << par[i] << " ";
    return 0;
}