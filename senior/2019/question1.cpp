#include <iostream>
#include <cstdint>

int main() {
    std::string in;
    std::cin >> in;

    std::uint64_t horizontal_count = 0;
    std::uint64_t vertical_count = 0;
    for (const char& c : in) {
        // input is either h or v, so a simple else works
        if (c == 'H') {
            horizontal_count++;
        } else {
            vertical_count++;
        }
    }

    if (vertical_count % 2 == 0) {
        if (horizontal_count % 2 == 0) {
            std::cout << "1 2\n3 4";
        } else {
            std::cout << "3 4\n1 2";
        }
    } else {
        if (horizontal_count % 2 == 0) {
            std::cout << "2 1\n4 3";
        } else {
            std::cout << "4 3\n2 1";
        }
    }

    return 0;
}