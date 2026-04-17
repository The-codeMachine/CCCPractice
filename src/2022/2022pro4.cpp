/*#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int sameCount;
    std::cin >> sameCount;

    std::vector<std::pair<std::string, std::string>> sameConstraints(sameCount);
    for (int i = 0; i < sameCount; ++i) {
        std::cin >> sameConstraints[i].first >> sameConstraints[i].second;
    }

    int diffCount;
    std::cin >> diffCount;

    std::vector<std::pair<std::string, std::string>> diffConstraints(diffCount);
    for (int i = 0; i < diffCount; ++i) {
        std::cin >> diffConstraints[i].first >> diffConstraints[i].second;
    }

    int groupCount;
    std::cin >> groupCount;

    std::unordered_map<std::string, int> groupOf;
    groupOf.reserve(groupCount * 3);

    for (int i = 0; i < groupCount; ++i) {
        std::string a, b, c;
        std::cin >> a >> b >> c;

        groupOf[a] = i;
        groupOf[b] = i;
        groupOf[c] = i;
    }

    int violations = 0;

    // Check "must be same group"
    for (const auto& [a, b] : sameConstraints) {
        if (groupOf[a] != groupOf[b]) {
            ++violations;
        }
    }

    // Check "must be different groups"
    for (const auto& [a, b] : diffConstraints) {
        if (groupOf[a] == groupOf[b]) {
            ++violations;
        }
    }

    std::cout << violations << "\n";

    return 0;
}
*/