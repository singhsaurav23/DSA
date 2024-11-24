class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());
        int n = clips.size();
        int i = 0, j = 0, c = 0;
        int maxReach = 0, maxEnd = 0;

        while (maxReach < time) {
            while (j < n && clips[j][0] <= maxReach) {
                maxEnd = max(maxEnd, clips[j][1]);
                j++;
            }
            if (maxReach == maxEnd) return -1;
            maxReach = maxEnd;
            c++;
        }
        return c;
    }
};