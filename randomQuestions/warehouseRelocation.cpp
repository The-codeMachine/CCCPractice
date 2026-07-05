#include <iostream>
#include <vector>
#include <algorithm>

// sorting algorithm + sliding window

inline size_t relocationCost(const std::vector<int>& warehouses) {
    size_t sum = 0;
    
    int c = warehouses[warehouses.size() / 2];
    for (int x : warehouses) {
        sum += std::abs(c - x);
    }

    return sum;
}

int main() {
    
    int k, n;
    std::cin >> n >> k;
    std::vector<int> warehouses(n);
    
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;

        warehouses[i] = x;
    }

    std::sort(warehouses.begin(), warehouses.end());

    size_t best = -1;
    k--;
    for (int i = k; i < n; ++i) {
        std::vector<int> v(warehouses.begin() + i - k, warehouses.begin() + i + 1);
        auto cost = relocationCost(v);
        if (cost < best)
            best = cost;
    }

    std::cout << best << "\n";

    return 0;
}