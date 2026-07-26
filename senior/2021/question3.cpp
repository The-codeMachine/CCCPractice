#include <iostream>
#include <cstdint>
#include <cmath>
#include <vector>

struct Friend {
    int position;
    int walkSpeed;
    int hearSpace;
};

uint64_t calculateCost(int c, int f, int w, int d) {
    double n = std::abs(c - f);
    if (n <= d)
        return 0;

    return (n - d) * w;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Friend> friends(n);

    uint32_t sP = -1;
    uint32_t bP = 0;
    for (int i = 0; i < n; ++i) {
        int p, w, d;
        std::cin >> p >> w >> d;
        friends[i] = {p, w, d};

        if (p < sP)
            sP = p;

        if (p > bP)
            bP = p;
    }

    bP++;
    int time;
    for (int i = sP; i < bP; ++i) {
        int currTime = 0;
        for (Friend f : friends) {
            currTime += calculateCost(i, f.position, f.walkSpeed, f.hearSpace);
        }

        if (currTime < time) 
            time = currTime;
    }

    std::cout << time << "\n";

    return 0;
}