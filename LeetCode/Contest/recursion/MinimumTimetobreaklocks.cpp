class Solution {
public:
    int recur(vector<int>& s, int k, int x, int cnt) {
        if (cnt == s.size()) {
            return 0;
        }
        int mi = 1e7;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == -1) continue;
            int z = s[i];
            s[i] = -1;
            int aa = z / x;
            if (z % x != 0) aa++;
            mi = min(mi, (aa + recur(s, k, x + k, cnt + 1)));
            s[i] = z;
        }
        return mi;
    }
    int findMinimumTime(vector<int>& s, int k) {
        // sort(s.begin(),s.end());
        return recur(s, k, 1, 0);
    }
};