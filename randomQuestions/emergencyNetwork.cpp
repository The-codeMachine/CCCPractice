#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> towers(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        towers[u].push_back(v);
    }
    
    int s;
    std::cin >> s;
    s--;

    size_t answer = 1;
    std::queue<int> q;
    std::vector<bool> visited(n);
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int tower = q.front();
        q.pop();

        for (const auto& neighbour : towers[tower]) {
            if (visited[neighbour])
                continue;

            visited[neighbour] = true;
            q.push(neighbour);
            answer++;
        }
    }

    std::cout << answer << "\n";

    return 0;
}