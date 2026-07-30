#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

struct Event {
    int position;
    int deltaChange;
};

uint64_t calculateCost(int c, int f, int w, int d) {
    int distance = std::abs(c - f);

    if (distance <= d)
        return 0;

    return static_cast<uint64_t>(distance - d) * w;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Event> events;
    events.reserve(2 * n);

    int64_t cost = 0;
    int64_t delta = 0;

    for (int i = 0; i < n; ++i) {
        int p, w, d;
        std::cin >> p >> w >> d;

        uint64_t cc = calculateCost(0, p, w, d);
        cost += cc;

        if (p - d > 0) {
            events.push_back({p - d, w});
        }

        events.push_back({p + d, w});

        if (cc > 0) 
            delta -= w;
    }

    std::sort(events.begin(), events.end(),
              [](const Event &a, const Event &b) {
                  return a.position < b.position;
              });

    int64_t best = cost;
    int lastPosition = 0;

    std::size_t i = 0;
    while (i < events.size()) {
        int currentPosition = events[i].position;

        cost += delta * static_cast<int64_t>(currentPosition - lastPosition);
        
        while (i < events.size() && events[i].position == currentPosition) {
            delta += events[i].deltaChange;
            ++i;
        }

        best = std::min(best, cost);
        lastPosition = currentPosition;
    }

    std::cout << best << '\n';

    return 0;
}