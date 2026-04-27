#include <iostream>
#include <string>

bool check(const std::string& str, int start) {
    char heavy = 0;

    // Determine heavy character from first relevant position
    for (size_t i = start; i < str.size(); i += 2) {
        if (heavy == 0) {
            heavy = str[i];
        } else if (str[i] != heavy) {
            return false;
        }
    }

    // Check the opposite positions
    for (size_t i = 1 - start; i < str.size(); i += 2) {
        if (str[i] == heavy) {
            return false;
        }
    }

    return true;
}

int main() {
    int t, n;
    std::cin >> t >> n;

    while (t--) {
        std::string str;
        std::cin >> str;

        // Defensive: don't trust n
        if (str.size() != (size_t)n) {
            std::cout << "F\n";
            continue;
        }

        if (check(str, 0) || check(str, 1)) {
            std::cout << "T\n";
        } else {
            std::cout << "F\n";
        }
    }

    return 0;
}