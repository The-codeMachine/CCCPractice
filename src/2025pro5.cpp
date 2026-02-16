/*#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    int rows;
    int cols;
    int max_val;

    std::cin >> rows >> cols >> max_val;

    // Build the map
    std::vector<std::vector<int>> map(rows, std::vector<int>(cols));

    int currentNum = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            map[i][j] = currentNum;
            currentNum = (currentNum == max_val) ? 1 : currentNum + 1;
        }
    }

    // DP table
    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols));

    // First row is base case
    for (int j = 0; j < cols; ++j) {
        dp[0][j] = map[0][j];
    }

    // Fill DP table
    for (int i = 1; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {

            int min_prev = dp[i - 1][j]; // directly above

            if (j > 0)
                min_prev = std::min(min_prev, dp[i - 1][j - 1]); // up-left

            if (j < cols - 1)
                min_prev = std::min(min_prev, dp[i - 1][j + 1]); // up-right

            dp[i][j] = map[i][j] + min_prev;
        }
    }

    // Find smallest value in last row
    int result = *std::min_element(dp[rows - 1].begin(), dp[rows - 1].end());

    std::cout << result << std::endl;

    return 0;
}
*/