// main intuiton if you need between absolute pairs and summation of that then for evry column you need to sort and then each a[i]*(n-1-i) - sum of remaining elments down(suffix)
// always try to maitain big elemnets-small elemnts together so that no rpoblem in absolute differnece.
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void sortColumns(vector<vector<ll>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return;

    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int col = 0; col < cols; ++col) {
        // Extract the column into a temporary vector
        vector<ll> column(rows);
        for (int row = 0; row < rows; ++row) {
            column[row] = matrix[row][col];
        }

        // Sort the column
        sort(column.begin(), column.end());

        // Write the sorted column back into the matrix
        for (int row = 0; row < rows; ++row) {
            matrix[row][col] = column[row];
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, i, j;
        cin >> n >> m;
        vector<vector<ll>> v(n, vector<ll>(m));
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }
        sortColumns(v);
        ll sum = 0;
        for (j = 0; j < m; j++) {
            ll s = 0;
            for (i = 0; i < n; i++) s += v[i][j];

            for (i = 0; i < n; i++) {
                s -= v[i][j];
                sum += abs((v[i][j] * (n - i - 1)) - s);
            }
        }
        cout << sum << endl;
    }
    return 0;
}