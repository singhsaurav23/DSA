//given values on a number line, sort it , last elemnt is ditribution center on right
// so for each query find the abs differnece nearest distribution center at right where query gives and add additional new distribtuion centres 
// solve it n<=1e5->use prefix sum to calculate the sum till that index and abs differnece prefix sum too. use that to + and - to find the solution from total summation

vector<long> getMi(vector<long>& v, vector<vector<long>>& w) {
    sort(v.begin(), v.end());
    long i, n = v.size(), s = 0;
    vector<long> pref(n), vv(n);
    for (i = 0; i < n; i++) {
        vv[i] = v[i];
        s += abs(v[n - 1] - v[i]);
        pref[i] = abs(v[n - 1] - v[i]);
    }
    for (i = 1; i < n; i++) {
        pref[i] += pref[i - 1];
        vv[i] += vv[i - 1];
    }
    vector<long> ans;
    for (i = 0; i < w.size(); i++) {
        long x = w[i][0], y = w[i][1], sum = s;

        sum -= pref[x - 1];
        sum += (x * v[x - 1]) - vv[x - 1];

        sum -= pref[y - 1] - pref[x - 1];

        sum += ((y - x) * v[y - 1]) - (vv[y - 1] - vv[x - 1]);

        ans.push_back(sum);
    }
    return ans;
}