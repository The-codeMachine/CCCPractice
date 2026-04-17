#include <iostream>
#include <vector>
#include <string>
#include <array>

constexpr std::array<std::pair<int, int>, 8> directions{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}}};

bool inBounds(int r, int c, int rows, int cols)
{
    return r >= 0 && r < rows &&
           c >= 0 && c < cols;
}

bool searchFrom(const std::vector<std::vector<char>> &grid,
                int startRow,
                int startCol,
                const std::string &word)
{
    int rows = grid.size();
    int cols = grid[0].size();

    if (grid[startRow][startCol] != word[0])
        return false;

    int length = word.size();

    for (auto [dr1, dc1] : directions)
    {
        // --------------------
        // 1) Straight check
        // --------------------
        {
            int r = startRow;
            int c = startCol;
            bool match = true;

            for (int i = 1; i < length; ++i)
            {
                r += dr1;
                c += dc1;

                if (!inBounds(r, c, rows, cols) ||
                    grid[r][c] != word[i])
                {
                    match = false;
                    break;
                }
            }

            if (match)
                return true;
        }

        // --------------------
        // 2) L-shape check
        // --------------------
        for (int turnIndex = 1; turnIndex < length; ++turnIndex)
        {
            int r = startRow;
            int c = startCol;
            bool valid = true;

            // first segment
            for (int i = 1; i <= turnIndex; ++i)
            {
                r += dr1;
                c += dc1;

                if (!inBounds(r, c, rows, cols) ||
                    grid[r][c] != word[i])
                {
                    valid = false;
                    break;
                }
            }

            if (!valid)
                continue;

            // try second direction
            for (auto [dr2, dc2] : directions)
            {
                // must turn
                if (dr1 == dr2 && dc1 == dc2)
                    continue;

                // must be perpendicular
                if (dr1 * dr2 + dc1 * dc2 != 0)
                    continue;

                int r2 = r;
                int c2 = c;
                bool match = true;

                for (int i = turnIndex + 1; i < length; ++i)
                {
                    r2 += dr2;
                    c2 += dc2;

                    if (!inBounds(r2, c2, rows, cols) ||
                        grid[r2][c2] != word[i])
                    {
                        match = false;
                        break;
                    }
                }

                if (match)
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    std::string word;
    std::cin >> word;

    int rows, cols;
    std::cin >> rows >> cols;

    std::vector<std::vector<char>> grid(rows, std::vector<char>(cols));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            std::cin >> grid[i][j];

    int numFound = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (searchFrom(grid, i, j, word))
                numFound++;
        }
    }

    std::cout << numFound;
}