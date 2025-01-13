class Solution {
public:
    int minimumLength(string s) {
        int i, n = s.size();
        int c = 0;
        vector<int> v(26, 0);
        for (i = 0; i < n; i++) {
            v[s[i] - 'a']++;
        }
        for (i = 0; i < 26; i++) {
            if (v[i] == 0) continue;
            if (v[i] % 2 == 0) c += 2;
            else c++;
        }
        return c;
    }
};