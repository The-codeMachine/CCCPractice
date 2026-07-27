#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

struct Friend {
    int position;
    int walkSpeed;
    int hearSpace;
};

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

    std::vector<Friend> friends;
    friends.reserve(n);

    std::vector<Event> events;
    events.reserve(2 * n);

    int64_t cost = 0;
    int64_t delta = 0;

    // Compute initial cost and initial slope at x = 0.
    for (int i = 0; i < n; ++i) {
        int p, w, d;
        std::cin >> p >> w >> d;

        p--;

        friends.push_back({p, w, d});

        cost += calculateCost(0, p, w, d);

        if (0 < p - d)
            delta -= w;
        else if (0 > p + d)
            delta += w;
        // otherwise delta += 0

        if (p - d >= 0)
            events.push_back({p - d - 1, w});

        events.push_back({p + d + 1, w});
    }

    std::sort(events.begin(), events.end(),
              [](const Event &a, const Event &b) {
                  return a.position < b.position;
              });

    std::cout << "Cost: " << cost << "\n";
    std::cout << "Delta: " << delta << "\n";

    for (Event e : events) {
        std::cout << "Event Position: " << e.position << "\nEvent Change: " << e.deltaChange << "\n\n";
    }

    int64_t best = cost;
    int lastPosition = 0;

    std::size_t i = 0;
    while (i < events.size()) {
        int currentPosition = events[i].position;

        cost += delta * static_cast<int64_t>(currentPosition - lastPosition - 1);
        best = std::min(best, cost);

        std::cout << "Cost: " << cost << "\n";

        while (i < events.size() && events[i].position == currentPosition) {
            delta += events[i].deltaChange;
            ++i;
        }

        std::cout << "Delta: " << delta << "\n";

        lastPosition = currentPosition;
    }

    std::cout << best << '\n';

    return 0;
}