#include <iostream>
#include <vector>

int main() {
    size_t n;
    std::cin >> n;

    std::vector<long> vec;
    vec.reserve(n);

    for (size_t i = 0; i < n; ++i) {
        long h;
        std::cin >> h;

        vec.push_back(h);
    }

    size_t num = 0;
    for (size_t i = 0; i < (n / 2); ++i) {
        if (vec[(n / 2) + i] == vec[i])
            num += 2;
    }

    std::cout << num << "\n";

    return 0;
}