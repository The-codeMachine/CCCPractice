#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<size_t>> constructMap(size_t maxValue, size_t rows, size_t columns)
{
    std::vector<std::vector<size_t>> map;

    size_t currentValue = 1;
    for (size_t i = 0; i < rows; ++i)
    {
        std::vector<size_t> row;

        for (size_t j = 0; j < columns; ++j)
        {
            row.push_back(currentValue);
            currentValue++;

            if (currentValue > maxValue)
            {
                currentValue = 1;
            }
        }

        map.push_back(row);
    }

    return map;
}

bool accessible(const std::vector<std::vector<size_t>> &map, size_t row, size_t col)
{
    if (row < map.size())
    {
        if (col < map[0].size())
        {
            return true;
        }
    }

    return false;
}

std::vector<size_t> simulatePath(const std::vector<std::vector<size_t>> &map, size_t row, size_t col)
{
    size_t cost = map[row][col];
    std::vector<size_t> pathCosts;

    if (accessible(map, row - 1, col - 1))
    {
        std::vector<size_t> paths = simulatePath(map, row - 1, col - 1);
        if (paths.empty())
        {
            pathCosts.push_back(cost);
        }
        else
        {
            std::sort(paths.begin(), paths.end());
            pathCosts.push_back(cost + paths[0]);
        }
    }

    if (accessible(map, row - 1, col))
    {
        std::vector<size_t> paths = simulatePath(map, row - 1, col);
        if (paths.empty())
        {
            pathCosts.push_back(cost);
        }
        else
        {
            std::sort(paths.begin(), paths.end());
            pathCosts.push_back(cost + paths[0]);
        }
    }

    if (accessible(map, row - 1, col + 1))
    {
        std::vector<size_t> paths = simulatePath(map, row - 1, col + 1);
        if (paths.empty())
        {
            pathCosts.push_back(cost);
        }
        else
        {
            std::sort(paths.begin(), paths.end());
            pathCosts.push_back(cost + paths[0]);
        }
    }

    if (pathCosts.empty())
        pathCosts.push_back(cost);

    return pathCosts;
}

int main()
{
    size_t rows, cols, maxValue;
    std::cin >> rows >> cols >> maxValue;

    std::vector<std::vector<size_t>> map = constructMap(maxValue, rows, cols);

    size_t smallest = -1;
    for (size_t i = 0; i < map[0].size(); ++i)
    {
        std::vector<size_t> costs = simulatePath(map, map.size() - 1, i);
        std::sort(costs.begin(), costs.end());
        if (costs[0] < smallest)
        {
            smallest = costs[0];
        }
    }

    std::cout << smallest << "\n";

    return 0;
}