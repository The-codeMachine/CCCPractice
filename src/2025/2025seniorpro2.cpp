#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string input;
    std::cin >> input;

    std::vector<std::pair<char, long long>> segments;

    for (size_t i = 0; i < input.size(); ) {
        char label = input[i++];

        long long value = 0;
        while (i < input.size() && isdigit(input[i])) {
            value = value * 10 + (input[i++] - '0');
        }

        segments.push_back({label, value});
    }

    long long total = 0;
    for (auto& [c, v] : segments)
        total += v;

    long long index;
    std::cin >> index;

    index %= total;

    for (auto& [c, v] : segments) {
        if (index < v) {
            std::cout << c << "\n";
            return 0;
        }

        index -= v;
    }


    return 0;
}