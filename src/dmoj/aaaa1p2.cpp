#include <iostream>
#include <set>
#include <cmath>

int main() {
    size_t n, m;
    std::cin >> n >> m;

    std::set<int> lights;
    std::set<int> friends;

    while (n--) {
        int l;
        std::cin >> l;
        lights.insert(l);
    }

    while (m--) {
        int f;
        std::cin >> f;
        friends.insert(f);
    }

    long long totalPower = 0;

    for (const auto& element : friends) {
        if (lights.count(element))
            continue;

        auto it = lights.lower_bound(element);

        int closest;

        if (it == lights.begin()) {
            // Only right neighbor exists
            closest = *it;
        } else if (it == lights.end()) {
            // Only left neighbor exists
            closest = *std::prev(it);
        } else {
            int right = *it;
            int left = *std::prev(it);

            if (std::abs(right - element) < std::abs(left - element))
                closest = right;
            else
                closest = left;
        }

        totalPower += std::abs(element - closest);

        // Fill in lights between closest and element
        if (closest < element) {
            for (int i = closest; i <= element; ++i)
                lights.insert(i);
        } else {
            for (int i = closest; i >= element; --i)
                lights.insert(i);
        }
    }

    std::cout << totalPower << "\n";
    return 0;
}