#include <iostream>
#include <queue>
#include <vector>

struct Station {
    std::vector<int> neighbours;
    bool repair; // true if it is
};


int main() {
    int n;
    std::cin >> n;

    std::vector<Station> stations(n);
    
    n--;
    for (int i = 0; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;

        u--;
        v--;

        if (v > u)
            stations[u].neighbours.push_back(v);
        else 
            stations[v].neighbours.push_back(u);
    }

    n++;
    for (int i = 0; i < n; ++i) {
        bool repair;
        std::cin >> repair;

        stations[i].repair = repair;
    }

    std::vector<int> answer(n);
    answer[0] = 0;

    std::queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int i = q.front();
        Station& s = stations[i];
        q.pop();
        
        for (int neighbour : s.neighbours) {
            if (stations[neighbour].repair) {
                answer[neighbour] = 0;
            } else {
                answer[neighbour] = answer[i] + 1;
            }

            q.push(neighbour);
        }
    }

    for (int i : answer) {
        std::cout << i << " ";
    }

    return 0;
}