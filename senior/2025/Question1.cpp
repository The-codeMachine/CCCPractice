#include <iostream>
#include <algorithm>

int main() {
    int a;
    int b;
    int x;
    int y;

    std::cin >> a >> b >> x >> y;

    int stacked = 0;
    int onTop = 0;

    stacked = (std::max(a, x) + b + y) * 2;
    onTop = (std::max(b, y) + a + x) * 2;

    std::cout << std::min(stacked, onTop) << "\n";

    return 0;
}