#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::vector<char>> visited;

bool canVisit(const std::vector<std::vector<char>> &map, int row, int col)
{
    if ((map.size() - 1) >= row && (map[0].size() - 1) >= col)
    {
        if (visited[row][col] == '#')
            return false;
        if (map[row][col] != '*')
            return true;
    }

    return false;
}

int visitSquare(const std::vector<std::vector<char>> &map, int row, int col)
{
    if (!canVisit(map, row, col))
        return 0;

    const char ch = map[row][col];
    int start = 0;

    if (ch == 'S')
        start++;
    else if (ch == 'M')
        start += 5;
    else if (ch == 'L')
        start += 10;

    visited[row][col] = '#';

    if (canVisit(map, row + 1, col))
    {
        start += visitSquare(map, row + 1, col);
    }
    if (canVisit(map, row - 1, col))
    {
        start += visitSquare(map, row - 1, col);
    }
    if (canVisit(map, row, col + 1))
    {
        start += visitSquare(map, row, col + 1);
    }
    if (canVisit(map, row, col - 1))
    {
        start += visitSquare(map, row, col - 1);
    }

    return start;
}

int main()
{
    int rows, cols;
    std::cin >> rows >> cols;

    std::vector<std::vector<char>> map;
    for (int i = 0; i < rows; ++i)
    {
        std::vector<char> row;
        for (int j = 0; j < cols; j++)
        {
            char ch;
            std::cin >> ch;

            row.push_back(ch);
        }

        map.push_back(row);
        visited.push_back(row);
    }

    int srow, scol;

    std::cin >> srow >> scol;

    int out = 0;
    out = visitSquare(map, srow, scol);

    std::cout << out << "\n";

    return 0;
}