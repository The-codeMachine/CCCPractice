#include <iostream>
#include <vector>
#include <cstdint>

bool isPalindromeRow(const std::vector<char>& row) {
    size_t size = row.size();
    int n = row.size() / 2;
    for (int i = 0; i < n; ++i) {
        if (row[i] != row[size - 1 - i]) {
            return false;
        }
    }

    return true;
}

bool isPalindromeColumn(const std::vector<char>& column) {
    size_t size = column.size();
    int n = column.size() / 2;
    for (int i = 0; i < n; ++i) {
        if (column[i] != column[size - 1 - i]) {
            return false;
        }
    }

    return true;
}

int main() {

    std::cout << "Tests\n";

    std::cout << isPalindromeColumn({'a', 'b', 'c', 'b', 'a'}) << "\n";
    std::cout << isPalindromeRow({'a', 'a', 'a'}) << "\n";
    std::cout << isPalindromeColumn({'a', 'b', 'b'}) << "\n";

    std::cout << "\n\n";

    // (n, m) == (5, 5)
    // r == 3
    // c == 4

    std::cout << "\nRows\n";

    std::cout << isPalindromeRow({'a', 'a', 'c', 'a', 'a'}) << "\n";
    std::cout << isPalindromeRow({'a', 'a', 'c', 'b', 'a'}) << "\n";
    std::cout << isPalindromeRow({'a', 'a', 'c', 'a', 'a'}) << "\n";
    std::cout << isPalindromeRow({'a', 'a', 'c', 'b', 'a'}) << "\n";
    std::cout << isPalindromeRow({'a', 'a', 'a', 'a', 'a'}) << "\n";

    std::cout << "\nColumns\n";

    std::cout << isPalindromeColumn({'a', 'a', 'a', 'a', 'a'}) << "\n";
    std::cout << isPalindromeColumn({'a', 'a', 'a', 'a', 'a'}) << "\n";
    std::cout << isPalindromeColumn({'c', 'c', 'c', 'c', 'a'}) << "\n";
    std::cout << isPalindromeColumn({'a', 'b', 'a', 'b', 'a'}) << "\n";
    std::cout << isPalindromeColumn({'a', 'a', 'a', 'a', 'a'}) << "\n";

    std::cout << "\n\n";

    // (n, m) == (4, 4)
    // r == 3
    // c == 4
    
    std::cout << "\nRows\n";

    std::cout << isPalindromeRow({'a', 'b', 'b', 'a'}) << "\n";
    std::cout << isPalindromeRow({'b', 'b', 'b', 'c'}) << "\n";
    std::cout << isPalindromeRow({'b', 'b', 'b', 'b'}) << "\n";
    std::cout << isPalindromeRow({'a', 'b', 'b', 'a'}) << "\n";

    // IMPOSSIBLE
    
    return 0;
}