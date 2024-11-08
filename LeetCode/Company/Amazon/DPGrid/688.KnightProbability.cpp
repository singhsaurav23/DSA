class Solution {
public:
    int total = 0;
    double memo(int i, int j, int n, int k, vector<vector<vector<double>>>& dp) {
        if (i < 0 || j < 0 || i >= n || j >= n) { total++; return 0; }
        if (k == 0) {
            return 1.0;
        }
        if (dp[i][j][k] != -1.0) return dp[i][j][k];
        return dp[i][j][k] = (double)((memo(i - 2, j - 1, n, k - 1, dp) + memo(i - 2, j + 1, n, k - 1, dp) +
            memo(i - 1, j + 2, n, k - 1, dp) + memo(i - 1, j - 2, n, k - 1, dp) + memo(i + 1, j + 2, n, k - 1, dp) +
            memo(i + 1, j - 2, n, k - 1, dp) + memo(i + 2, j - 1, n, k - 1, dp) + memo(i + 2, j + 1, n, k - 1, dp)) / 8.0);
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(k + 1, -1.0)));
        return memo(row, column, n, k, dp);

    }
};

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        // Define possible directions for the knight's moves
        vector<pair<int, int>> directions = {
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
        };

        // Initialize the previous and current DP tables
        vector prevDp(n, vector<double>(n, 0));
        vector currDp(n, vector<double>(n, 0));

        // Set the probability of the starting cell to 1
        prevDp[row][column] = 1;

        // Iterate over the number of moves
        for (int moves = 1; moves <= k; moves++) {
            // Iterate over the cells on the chessboard
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    currDp[i][j] = 0;

                    // Iterate over possible directions
                    for (const auto& direction : directions) {
                        int prevI = i - direction.first;
                        int prevJ = j - direction.second;

                        // Check if the previous cell is within the chessboard
                        if (prevI >= 0 && prevI < n && prevJ >= 0 && prevJ < n) {
                            // Update the probability by adding the previous probability divided by 8
                            currDp[i][j] += prevDp[prevI][prevJ] / 8;
                        }
                    }
                }
            }

            // Swap the previous and current DP tables
            prevDp.swap(currDp);
        }

        // Calculate the total probability by summing up the probabilities for all cells
        double totalProbability = 0;
        for (const auto& row : prevDp) {
            for (const auto& cell : row) {
                totalProbability += cell;
            }
        }

        // Return the total probability
        return totalProbability;
    }
};