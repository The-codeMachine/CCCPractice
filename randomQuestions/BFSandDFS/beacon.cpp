#include <iostream>
#include <vector>
#include <queue>

struct Tower {
    std::vector<int> neighbours;
    int maxDelay;
};

int main() {
    int N;
    std::cin >> N;

    std::vector<Tower> towers(N);

    // Read edges
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;

        --u;
        --v;

        towers[u].neighbours.push_back(v);
        towers[v].neighbours.push_back(u);
    }

    // Read delays
    for (int i = 0; i < N; i++) {
        std::cin >> towers[i].maxDelay;
    }

    int answer = 0;

    // Try every beacon location
    for (int start = 0; start < N; start++) {

        std::vector<int> distance(N, -1);
        std::queue<int> q;

        distance[start] = 0;
        q.push(start);

        while (!q.empty()) {

            int current = q.front();
            q.pop();

            for (int next : towers[current].neighbours) {

                if (distance[next] == -1) {
                    distance[next] = distance[current] + 1;
                    q.push(next);
                }
            }
        }

        bool valid = true;

        for (int i = 0; i < N; i++) {

            if (distance[i] > towers[i].maxDelay) {
                valid = false;
                break;
            }
        }

        if (valid)
            answer++;
    }

    std::cout << answer << '\n';

    return 0;
}