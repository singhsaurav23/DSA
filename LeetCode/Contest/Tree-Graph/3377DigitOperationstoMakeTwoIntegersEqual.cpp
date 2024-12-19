//dijkstra + prime+seive
#include <stdlib.h>
class Solution {


public:
    static const int MAX_NUM = 10000;
    bool prime[MAX_NUM];

    void precomputePrimes() {
        fill(prime, prime + MAX_NUM, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i * i < MAX_NUM; i++) {
            if (prime[i]) {
                for (int j = i * i; j < MAX_NUM; j += i) {
                    prime[j] = false;
                }
            }
        }
    }
    vector<int> get_neigh(int curr, int length) {
        vector<int> neighbors;
        string s = to_string(curr);

        for (int i = 0; i < s.length(); i++) {
            int digit = s[i] - '0';

            if (digit < 9) {
                string sb = s;
                sb[i] = (char)(digit + 1 + '0');
                int val = stoi(sb);
                if (!prime[val]) {
                    neighbors.push_back(val);
                }
            }

            if (digit > 0) {
                string sb = s;
                sb[i] = (char)(digit - 1 + '0');
                int val = stoi(sb);
                if (!prime[val]) {
                    neighbors.push_back(val);
                }
            }
        }
        return neighbors;
    }

    int minOperations(int n, int m) {
        precomputePrimes();

        if (prime[n] || prime[m]) return -1;
        if (n == m) return n;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ n,n });
        int len = to_string(n).size();
        //cout<<len<<" ";
        vector<int> dis(10001, INT_MAX);
        //cout<<dis[0];
        dis[n] = n;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            long long cost = curr.first;
            long long node = curr.second;

            if (cost > dis[node]) continue;

            if (node == m) return (int)cost;
            for (int nxt : get_neigh(node, len)) {
                long long newCost = cost + nxt;
                if (newCost < dis[nxt]) {
                    dis[nxt] = newCost;
                    pq.push({ newCost,nxt });
                }
            }
        }
        return -1;

    }
};