#include <iostream>

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        size_t a;
        size_t b;
        size_t p;
        std::cin >> a >> b >> p;

        if (a * b == p)
            std::cout << "POSSIBLE DOUBLE SIGMA\n";
        else 
            std::cout << "16 BIT S/W ONLY\n";
    }

    return 0;
}