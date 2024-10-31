/*You have a list of n items with their original prices in array 'prices'. You have m discount coupons, 
where each coupon can be applied to any item and reduces its price to floor(price/2). 
You can apply multiple coupons to the same item. Find the minimum total cost possible after applying all m coupons optimally.
m<=1e9 n<=1e5 a[i]<=1e9 */


class Solution {
public:
    long long minimumSum(vector<int>& arr, long long m) {
        if (m >= (long long)arr.size() * 31) return 0; // time optimization

        priority_queue<long long> pq(arr.begin(), arr.end());
        while (m--) {
            long long top = pq.top();
            pq.pop();
            pq.push(top / 2);
        }

        long long sum = 0;
        while (!pq.empty()) sum += pq.top(), pq.pop();
        return sum;
    }
};