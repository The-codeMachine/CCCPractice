#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

std::vector<std::vector<size_t>> constructMap(size_t maxValue, size_t rows, size_t columns)
{
    std::vector<std::vector<size_t>> map(rows, std::vector<size_t>(columns));

    size_t currentValue = 1;
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            map[i][j] = currentValue++;
            if (currentValue > maxValue)
                currentValue = 1;
        }
    }

    return map;
}

int main()
{
    size_t rows, cols, maxValue;
    std::cin >> rows >> cols >> maxValue;

    auto map = constructMap(maxValue, rows, cols);

    // dp[r][c] = minimum cost to reach cell (r,c) from top
    std::vector<std::vector<size_t>> dp(rows, std::vector<size_t>(cols));

    // Base case: first row
    for (size_t c = 0; c < cols; ++c)
        dp[0][c] = map[0][c];

    // Fill DP table
    for (size_t r = 1; r < rows; ++r)
    {
        for (size_t c = 0; c < cols; ++c)
        {
            size_t best = dp[r - 1][c];

            if (c > 0)
                best = std::min(best, dp[r - 1][c - 1]);

            if (c + 1 < cols)
                best = std::min(best, dp[r - 1][c + 1]);

            dp[r][c] = map[r][c] + best;
        }
    }

    size_t smallest = *std::min_element(dp[rows - 1].begin(), dp[rows - 1].end());

    std::cout << smallest << "\n";
}