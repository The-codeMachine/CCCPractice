#include <iostream>
#include <vector>
#include <unordered_map>

bool testP(size_t p, const std::vector<long long>& cards, size_t N)
{
    std::vector<long long> pref(N + 1, 0);

    std::unordered_map<long long, std::vector<int>> positions;

    for (size_t i = 1; i <= N; ++i)
    {
        pref[i] = (pref[i - 1] + cards[i - 1]) % p;
    }

    for (size_t i = 0; i <= N; ++i)
    {
        positions[pref[i]].push_back(static_cast<int>(i));
    }

    for (auto& [residue, vec] : positions)
    {
        if (vec.size() >= 3)
        {
            int a = vec[0];
            int b = vec[1];
            int c = vec[2];

            std::cout << "YES\n";

            std::cout << (b - a) << '\n';
            for (int i = a + 1; i <= b; ++i)
            {
                std::cout << i << ' ';
            }
            std::cout << '\n';

            std::cout << (c - b) << '\n';
            for (int i = b + 1; i <= c; ++i)
            {
                std::cout << i << ' ';
            }
            std::cout << '\n';

            return true;
        }
    }

    return false;
}

int main()
{
    size_t N;
    std::cin >> N;

    std::vector<long long> cards;
    cards.reserve(N);
    size_t largestValue = 0;
    for (size_t i = 0; i < N; ++i)
    {
        long long num;
        std::cin >> num;
        cards.push_back(num);

        if (num > largestValue)
            largestValue = num;
    }

    for (size_t i = 0; i * i < largestValue; i += 2)
    {
        for (auto &num : cards)
        {
            if (num % i == 0)
            {
                if (testP(i, cards, N))
                    return 0;
            }
        }
    }

    std::cout << "NO\n";

    return 0;
}