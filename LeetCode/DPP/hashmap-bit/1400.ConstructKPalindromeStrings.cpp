class Solution {
public:
    bool canConstruct(string s, int k) {
        int i, n = s.size();
        vector<int> v(26, 0);
        for (i = 0; i < n; i++) {
            v[s[i] - 'a']++;
        }int c = 0, c1 = 0;
        for (i = 0; i < 26; i++) {
            if (v[i] % 2) c++;
            else if (v[i] > 0)c1++;
        }
        if (c <= k && n >= k) return true;
        else return false;
    }
};

class Solution {
public:
    bool canConstruct(string s, int k) {
        // Handle edge cases
        if (s.length() < k) return false;
        if (s.length() == k) return true;

        // Initialize oddCount as an integer bitmask
        int oddCount = 0;

        // Update the bitmask for each character in the string
        for (char chr : s) {
            oddCount ^= 1 << (chr - 'a');
        }

        // Count the number of set bits in the bitmask
        int setBits = __builtin_popcount(oddCount);

        // Return if the number of odd frequencies is less than or equal to k
        return setBits <= k;
    }
};