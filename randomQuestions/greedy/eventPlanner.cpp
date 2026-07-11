#include <algorithm>
#include <iostream>
#include <vector>

struct Event {
    unsigned long start, end;
};

int main() {
    size_t n;
    std::cin >> n;

    std::vector<Event> events(n);
    for (auto& e : events)
        std::cin >> e.start >> e.end;

    std::sort(events.begin(), events.end(),
              [](const Event& a, const Event& b) {
                  return a.end < b.end;
              });

    unsigned long currentEnd = 0;
    size_t answer = 0;

    for (const auto& e : events) {
        if (e.start >= currentEnd) {
            ++answer;
            currentEnd = e.end;
        }
    }

    std::cout << answer << '\n';
}