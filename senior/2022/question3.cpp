#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::uint64_t k;

    std::cin >> n >> m >> k;

    std::vector<int> numbers(n);

    std::uint64_t remainingK = k;

    for (int i = 0; i < n; ++i) {
        const std::uint64_t remainingPositions = n - i - 1;
        const std::uint64_t maximumContribution = std::min<std::uint64_t>(i + 1, m);

        // We must leave at least one good sample
        // for every remaining position.
        const std::uint64_t contribution = std::min(maximumContribution, remainingK - remainingPositions);

        if (contribution == 0) {
            std::cout << -1 << '\n';
            return 0;
        }

        if (contribution > static_cast<std::uint64_t>(i)) {
            // Need a completely new value.
            numbers[i] = std::min(i + 1, m);
        } else {
            // Reuse the value contribution positions back.
            numbers[i] = numbers[i - contribution];
        }

        remainingK -= contribution;
    }

    if (remainingK != 0) {
        std::cout << -1 << '\n';
        return 0;
    }

    for (int value : numbers) {
        std::cout << value << ' ';
    }

    std::cout << '\n';
}