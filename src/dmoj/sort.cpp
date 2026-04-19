#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    size_t size;
    std::cin >> size;

    std::vector<int> vec;
    vec.reserve(size);

    for (size_t i = 0; i < size; ++i) {
        int k;
        std::cin >> k;

        vec.push_back(k);
    }

    std::sort(vec.begin(), vec.end());

    for (size_t i = 0; i < size; ++i) {
        std::cout << vec[i] << "\n";
    }

    return 0;
}