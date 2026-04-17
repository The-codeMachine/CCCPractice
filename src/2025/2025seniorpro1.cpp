#include <iostream>

int main() {
    int a, b; // painting 1
    int x, y; // painting 2

    std::cin >> a >> b >> x >> y;

    int horizontal = 2 * ((a + x) + std::max(b, y));
    int vertical = 2 * (std::max(a, x) + (b + y));

    std::cout << std::min(horizontal, vertical) << "\n";

    return 0;
}