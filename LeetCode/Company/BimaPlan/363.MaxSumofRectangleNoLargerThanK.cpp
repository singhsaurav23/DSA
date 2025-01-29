//brute force 2d prefix sum TC->O(N*M*N*M)
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int kk) {
        int i, j, n = matrix.size(), m = matrix[0].size(), k, mm;
        vector<vector<int>> pre(n, vector<int>(m, 0));
        int ans = INT_MIN;

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (matrix[i][j] <= kk) ans = max(ans, matrix[i][j]);
            }
        }
        pre[0][0] = matrix[0][0];
        for (j = 1; j < m; j++) {
            pre[0][j] = pre[0][j - 1] + matrix[0][j];
        }
        for (j = 1; j < n; j++) {
            pre[j][0] = pre[j - 1][0] + matrix[j][0];
        }
        for (i = 1; i < n; i++) {
            for (j = 1; j < m; j++) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + matrix[i][j] - pre[i - 1][j - 1];
            }
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                for (k = i; k < n; k++) {
                    for (mm = j; mm < m; mm++) {
                        if (i == k && j == mm) continue;
                        int xx = pre[k][mm];

                        if ((i - 1) >= 0 && (j - 1) >= 0)
                            xx += pre[i - 1][j - 1];
                        if ((i - 1) >= 0)
                            xx -= pre[i - 1][mm];
                        if ((j - 1) >= 0)
                            xx -= pre[k][j - 1];
                        if (xx <= kk)
                            ans = max(ans, xx);
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    // maximum subarray sum less than equal to k -> find cur_sum-k pos itio so that prefix sum l,r region can be found out
    // for positive numbers->skiding window will work but for this we need nlogn approach
    int maxK(vector<int>& v, int kk) {
        int i, n = v.size(), ma = INT_MIN, s = 0;
        set<int> st = { 0 };
        for (i = 0; i < n; i++) {
            s += v[i];
            auto it = st.lower_bound(s - kk);
            if (it != st.end()) ma = max(ma, s - *it);
            st.insert(s);
        }
        return ma;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int kk) {
        int i, j, n = matrix.size(), m = matrix[0].size(), k, ans = INT_MIN;
        for (i = 0; i < m; i++) {
            vector<int> v(n, 0);
            for (j = i; j < m; j++) {
                for (k = 0; k < n; k++) v[k] += matrix[k][j];
                int x = maxK(v, kk);
                ans = max(ans, x);
            }
        }
        return ans;
    }
};

///O(M*M*NLOGN)
//kadane algo optimization if max sum less than k use that otherwise set approach 
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& m, int k) {
        int res = INT_MIN, rows = m.size(), cols = m[0].size();
        for (int l = 0; l < cols; ++l) {
            vector<int> sums(rows);
            for (int r = l; r < cols; ++r) {
                int kadane = 0, max_kadane = INT_MIN;
                for (int i = 0; i < rows; ++i) {
                    sums[i] += m[i][r];
                    kadane = max(kadane + sums[i], sums[i]);
                    max_kadane = max(max_kadane, kadane);
                }
                if (max_kadane <= k) {
                    res = max(res, max_kadane);
                    continue;
                }
                set<int> s = { 0 };
                int run_sum = 0;
                for (int sum : sums) {
                    run_sum += sum;
                    auto it = s.lower_bound(run_sum - k);
                    if (it != end(s))
                        res = max(res, run_sum - *it);
                    s.insert(run_sum);
                }
            }
        }
        return res;
    }
};