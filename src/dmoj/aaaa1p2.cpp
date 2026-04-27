#include <iostream>
#include <set>
#include <queue>
#include <unordered_set>

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::set<int> lights;
    std::unordered_set<int> friends;

    for (size_t i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        lights.insert(x);
    }

    for (size_t i = 0; i < m; ++i)
    {
        int x;
        std::cin >> x;
        friends.insert(x);
    }

    std::queue<std::pair<int, int>> q; // {position, distance}
    std::unordered_set<int> visited;

    // Initialize BFS with all lights
    for (int l : lights)
    {
        q.push({l, 0});
        visited.insert(l);
    }

    size_t totalPower = 0;
    size_t found = 0;

    while (!q.empty() && found < friends.size())
    {
        auto [pos, dist] = q.front();
        q.pop();

        if (friends.count(pos))
        {
            totalPower += dist;
            friends.erase(pos);
            found++;
        }

        // expand left
        if (!visited.count(pos - 1))
        {
            visited.insert(pos - 1);
            q.push({pos - 1, dist + 1});
        }

        // expand right
        if (!visited.count(pos + 1))
        {
            visited.insert(pos + 1);
            q.push({pos + 1, dist + 1});
        }
    }

    std::cout << totalPower << "\n";
}