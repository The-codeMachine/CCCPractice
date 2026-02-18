#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, T;
    std::cin >> N >> T;

    // 1-indexed grid for easier prefix math
    std::vector<std::vector<int>> grid(N + 1, std::vector<int>(N + 1, 0));

    // Read tree coordinates
    for (int i = 0; i < T; ++i) {
        int r, c;
        std::cin >> r >> c;
        grid[r][c] = 1;
    }

    // Build prefix sum array
    std::vector<std::vector<int>> prefix(N + 1, std::vector<int>(N + 1, 0));

    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= N; ++c) {
            prefix[r][c] = grid[r][c]
                + prefix[r - 1][c]
                + prefix[r][c - 1]
                - prefix[r - 1][c - 1];
        }
    }

    int maxArea = 0;

    // Try all possible squares
    for (int r1 = 1; r1 <= N; ++r1) {
        for (int c1 = 1; c1 <= N; ++c1) {

            // Maximum possible side length from this position
            int maxSide = std::min(N - r1 + 1, N - c1 + 1);

            for (int side = 1; side <= maxSide; ++side) {
                int r2 = r1 + side - 1;
                int c2 = c1 + side - 1;

                int trees =
                    prefix[r2][c2]
                    - prefix[r1 - 1][c2]
                    - prefix[r2][c1 - 1]
                    + prefix[r1 - 1][c1 - 1];

                if (trees == 0) {
                    maxArea = std::max(maxArea, side * side);
                }
            }
        }
    }

    std::cout << std::sqrt(maxArea) << "\n";

    return 0;
}
