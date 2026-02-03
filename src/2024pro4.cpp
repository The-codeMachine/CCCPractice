#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>

bool sharesValue(const std::unordered_map<char, int> map1, const std::unordered_map<char, int> map2) {
    std::unordered_set<int> values;

    for (const auto& [key, value] : map2)
        values.insert(value);

    for (const auto& [key, value] : map1) {
        if (values.count(value))
            return true;
    }

    return false;
}

int main() {
    std::string typed;
    std::string displayed;

    std::cin >> typed;
    std::cin >> displayed;

    std::unordered_map<char, int> typedUnique;
    std::unordered_map<char, int> displayedUnique;

    char original = '-';
    char replaced = '-';
    char silent = '-';

    for (const char& ch : typed) {
        typedUnique[ch]++;
    }

    for (const char& ch : displayed) {
        displayedUnique[ch]++;
    }

    for (auto const& pair : typedUnique) {
        if (displayedUnique.count(pair.first))
            continue;

        if (!displayedUnique.count(replaced) || !typedUnique.count(original))
            for (auto const& pair2 : displayedUnique) {
                if (pair.second == pair2.second && pair.first != pair2.first) {
                    original = pair.first;
                    replaced = pair2.first;

                    continue;
                }
            }

        silent = pair.first;

        if (silent != '-' && original != '-' && replaced != '-')
            break;
    }

    std::cout << original << " " << replaced << "\n" << silent << "\n";

    return 0;
}
