#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    size_t N;
    std::cin >> N;

    std::vector<long long> cards;
    cards.reserve(N);
    for (size_t i = 0; i < N; ++i) {
        long long num;
        std::cin >> num;

        cards.push_back(num);
    } 

    if (N < 4) {
        // brute force
    } else {
        size_t evenNumOne = 0;
        size_t evenNumTwo = 0;
        size_t oddNumOne = 0;
        size_t oddNumTwo = 0;
        for (size_t i = 0; i < N; ++i) {            
            if (cards[i] % 2 == 0) {
                std::cout << "even: " << i << "\n";

                if (evenNumOne != 0) {
                    evenNumTwo = i;

                    std::cout << "YES\n";
                    std::cout << "1 1\n";
                    std::cout << evenNumOne + 1 << "\n" << evenNumTwo + 1 << "\n";

                    return 0;
                }

                evenNumOne = i;
            } else {
                std::cout << "odd: " << i << "\n";

                if (oddNumOne != 0) {
                    oddNumTwo = i;

                    std::cout << "YES\n";
                    std::cout << "1 1\n";
                    std::cout << oddNumOne + 1 << "\n" << oddNumTwo + 1 << "\n";

                    return 0;
                }

                oddNumOne = i;
            }
        }
    }

    return 0;
}