#include <iostream>

int main() {
    size_t t;
    std::cin >> t;

    while (t--) {
        size_t k = 0;
        std::cin >> k;

        bool thing = true;
        while (thing) {
            k++;

            if (k * k * k % 1000 == 888) {
                thing = false;
                std::cout << k << "\n";
            }
        }  
    }

    return 0;
}