//use previous and store answer how can every one's contribute to i think

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), i, j;
        vector<int> v(n);
        int prev = 0, c = 0, prev1 = 0, c1 = 0;
        for (i = 0; i < n; i++) {
            //left pass
            int y = c1 + prev1;
            v[i] += y;
            prev1 = y;
            if (boxes[i] == '1') c1++;

            //right pass
            j = n - i - 1;
            int x = c + prev;
            v[j] += x;
            prev = x;
            if (boxes[j] == '1') c++;
        }

        return v;
    }
};