class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> vt(200, 0);
        vector<int> vs(200, 0);
        int i, j;
        for (i = 0; i < t.size(); i++) vt[t[i] - 'A']++;
        int cnt = 0, ans = INT_MAX, x = -1, y = -1;
        i = 0, j = 0;
        while (j < s.size()) {
            while (i<j && vs[s[i] - 'A']>vt[s[i] - 'A']) {
                vs[s[i] - 'A']--;
                i++;
            }
            if (cnt == t.size() && ans > (j - i)) {
                ans = j - i;
                x = i;
                y = j;
            }
            if (vt[s[j] - 'A'] > 0 && vs[s[j] - 'A'] < vt[s[j] - 'A']) cnt++;
            vs[s[j] - 'A']++;
            j++;
        }
        while (i<s.size() && vs[s[i] - 'A']>vt[s[i] - 'A']) {
            vs[s[i] - 'A']--;
            i++;
        }

        if (cnt == t.size() && ans > (j - i)) {
            ans = j - i;
            x = i;
            y = j;
        }
        if (x == -1 || y == -1) return "";
        return s.substr(x, y - x);
    }
};