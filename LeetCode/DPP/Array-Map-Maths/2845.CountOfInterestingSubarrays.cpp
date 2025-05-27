/*
* (S1 - s2+m) % m = k
* (s1%m - s2%m )%m =k
* (r1-r2+m)%m = k
* (r1-k+m)%m = r2
mp[r1++] and find mp[r2]
*/

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        unordered_map<int, long long> mp;
        mp[0] = 1;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % m == k) nums[i] = 1;
            else nums[i] = 0;
            if (i > 0) nums[i] += nums[i - 1];
            int x = (nums[i] % m - k + m) % m;
            if (mp.count(x)) ans += mp[x];
            mp[nums[i] % m]++;
        }
        return ans;
    }
};