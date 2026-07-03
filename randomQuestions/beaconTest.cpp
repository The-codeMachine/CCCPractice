#include <iostream>
#include <random>
#include <vector>

int main()
{
    std::mt19937 rng(std::random_device{}());

    constexpr int MAX_N = 5000;

    std::uniform_int_distribution<int> sizeDist(1, MAX_N);

    int n = sizeDist(rng);

    std::cout << n << '\n';

    // Random tree
    for (int i = 2; i <= n; i++)
    {
        std::uniform_int_distribution<int> parent(1, i - 1);

        std::cout << parent(rng) << ' ' << i << '\n';
    }

    // Random delays
    std::uniform_int_distribution<int> delay(0, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << delay(rng);

        if (i + 1 != n)
            std::cout << ' ';
    }

    std::cout << '\n';
}