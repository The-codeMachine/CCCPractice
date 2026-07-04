#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<std::vector<int>, int>> stations(n, {{}, -1});
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;

        u--; v--;

        stations[u].first.push_back(v);
        stations[v].first.push_back(u);
    }

    int s;
    std::cin >> s;
    s--;

    std::queue<int> q;
    std::vector<int> minutes;
    q.push(s);
    stations[s].second = 0;
    while (!q.empty()) {
        auto& station = stations[q.front()];
        q.pop();

        int nextMinute = station.second + 1;
        for (auto& s : station.first) {
            if (stations[s].second <= -1) {
                stations[s].second = nextMinute;
                q.push(s);
                
                
                if (minutes.size() < nextMinute) 
                    minutes.push_back(1);
                else {
                    minutes[nextMinute - 1] += 1;
                }
            }
        }
    }

    std::cout << '1' << "\n";
    for (int m : minutes) {
        std::cout << m << "\n";
    }

    return 0;
}