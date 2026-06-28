#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::string in;
    std::cin >> in;

    std::vector<std::pair<char, long long>> chars;
    size_t total = 0;
    for (size_t i = 0; i < in.size();) {
        char label = in[i++];

        long long value = 0;
        while (i < in.size() && std::isdigit(in[i])) {
            value = value * 10 + (in[i++] - '0');
        }

        chars.push_back({label, value});
        total += value;
    }

    long long index;
    std::cin >> index;

    index %= total;
    for (auto& [c, v] : chars) {
        if (index < v) {
            std::cout << c << "\n";
            return 0;
        }

        index -= v;
    }

    return 0;
}