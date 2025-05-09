﻿// either select song or take same song so numbe rof ways will be n* n-1 * n-2 ....
// dp state will number of songs played and number of songs selected so that we can find ways by remaining songs..and last k osngs should n't be there if same song playe again
// undertsand the state and ways and logical intutuion to use subprobelem to find witn two ways ether select same or take another
//logic- >

/*
* For the very first song in the playlist, you have i choices because you have i unique songs. So, you pick one song out of i possibilities.
For the second song, since it cannot be the same as the first one, you have i−1 choices. You've already played one song, and you can't repeat it yet, so you have one fewer choice.
You keep picking new songs for the first k songs in the playlist. For the third song, you have i−2 choices, for the fourth one i−3 choices, and so on, until the k-th song, for which you have i−(k−1) choices.
Now, for the (k+1)-th song and onwards, the only banned songs are k last played songs. Thus, each of the remaining goal−k songs has i−k possible choices.
This leads us to the formula for f(i): f(i)=i⋅(i−1)⋅(i−2)⋅⋯⋅(i−k+1)⋅(i−k)**(goal−k)
*/
class Solution {
public:
    long mod = 1e9 + 7;

    int memo(int i, int j, int goal, int n, int k, vector<vector<long>>& dp) {
        if (i == goal) {
            if (j == n) return 1;
            else return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];
        long cur = 0;
        if (j < n)
            cur += (memo(i + 1, j + 1, goal, n, k, dp) % mod * (n - j) % mod) % mod;
        if (j > k)
            cur += (memo(i + 1, j, goal, n, k, dp) % mod * (j - k) % mod) % mod;
        return dp[i][j] = cur;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long>> dp(goal + 1, vector<long>(n + 1, -1));
        return memo(0, 0, goal, n, k, dp);
    }
};

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int MOD = 1e9 + 7;

        // Initialize the DP table
        vector<vector<long>> dp(goal + 1, vector<long>(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= min(i, n); j++) {
                // The i-th song is a new song
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) % MOD;
                // The i-th song is a song we have played before
                if (j > k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] * (j - k)) % MOD;
                }
            }
        }

        return dp[goal][n];
    }
};