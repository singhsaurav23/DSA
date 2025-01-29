//swap or no swap, if previous swap then check with swapped element ocndition

class Solution {
public:
    int swapss(int i, bool isswap, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if (i == nums1.size()) {
            return 0;
        }
        if (dp[i][isswap] != -1) return dp[i][isswap];
        int t = INT_MAX, nt = INT_MAX;
        if (isswap) {
            if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i])
                t = swapss(i + 1, 0, nums1, nums2, dp);
            if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i])
                nt = 1 + swapss(i + 1, 1, nums1, nums2, dp);
        }
        else {
            if (i == 0) {
                t = swapss(i + 1, 0, nums1, nums2, dp);
                nt = 1 + swapss(i + 1, 1, nums1, nums2, dp);
            }
            else {
                if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i])
                    t = swapss(i + 1, 0, nums1, nums2, dp);

                if ((i - 1) >= 0 && nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i])
                    nt = 1 + swapss(i + 1, 1, nums1, nums2, dp);
            }
        }
        return dp[i][isswap] = min(t, nt);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(2, -1));
        return swapss(0, 0, nums1, nums2, dp);
    }
};