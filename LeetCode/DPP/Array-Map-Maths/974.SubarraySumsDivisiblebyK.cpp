/*
* (S1 - s2) % m = 0
* (s1%m - s2%m)%m =0
* (r1-r2+m)%m = 0
* (r1+m)%m = r2

*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int i, s = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (i = 0; i < nums.size(); i++) {
            if (i > 0) nums[i] += nums[i - 1];
            if (mp.count(((nums[i] % k) + k) % k))
                s += mp[((nums[i] % k) + k) % k];
            mp[((nums[i] % k) + k) % k]++;
        }
        return s;
    }
};