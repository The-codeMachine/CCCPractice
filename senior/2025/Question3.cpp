#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>

static const uint32_t null = -1;

size_t calculatePrettiness(const std::vector<std::pair<uint32_t, uint32_t>> &pens,
                           const std::unordered_map<uint32_t, std::pair<uint32_t, uint32_t>> &maxPrettiness,
                           uint32_t lowestFirst, uint32_t highestSecond)
{
    size_t prettiness = 0;
    for (const auto &pair : maxPrettiness)
    {
        prettiness += pens[pair.first].second;
    }

    if (pens[lowestFirst].second < pens[highestSecond].second)
    {
        prettiness -= pens[lowestFirst].second;
        prettiness += pens[highestSecond].second;
    }

    return prettiness;
}

int main()
{
    uint32_t n;
    uint32_t m;
    uint32_t q;

    std::cin >> n >> m >> q;

    std::vector<std::pair<uint32_t, uint32_t>> pens;
    pens.reserve(n);
    std::unordered_map<uint32_t, std::pair<uint32_t, uint32_t>> maxPrettiness;

    uint32_t lowestFirst = 0;
    uint32_t highestSecond = 0;
    for (uint32_t i = 0; i < n; ++i)
    {
        uint32_t colour;
        uint32_t prettiness;

        std::cin >> colour >> prettiness;

        pens.push_back({colour, prettiness});

        if (maxPrettiness.count(colour) == 0)
        {
            maxPrettiness[colour] = {i, null};

            if (pens[lowestFirst].second > prettiness)
                lowestFirst = i;

            continue;
        }
        else
        {
            auto& pair = maxPrettiness[colour];

            if (pens[pair.first].second < prettiness)
            {
                pair.second = pair.first;
                pair.first = i;

                if (pens[lowestFirst].second > prettiness)
                    lowestFirst = i;

                continue;
            }
            else if (pair.second == null)
            {
                pair.second = i;

                if (pens[highestSecond].second < prettiness)
                    highestSecond = i;

                continue;
            }
            else if (pens[pair.second].second < prettiness)
            {
                pair.second = i;

                if (pens[highestSecond].second < prettiness)
                    highestSecond = i;

                continue;
            }
        }
    }

    std::cout << lowestFirst << " " << highestSecond << "\n";

    std::cout << calculatePrettiness(pens, maxPrettiness, lowestFirst, highestSecond) << "\n";

    /*
    while (q--) {
        uint32_t operation;
        uint32_t pen;
        uint32_t newValue;

        std::cin >> operation >> pen >> newValue;
        pen--;

        if (operation == 1) {

        } else {
            pens[pen].second = newValue;
            const auto& pair = maxPrettiness[pens[pen].first];

            if (pair.first == pen) {

            }
        }
    } */

    return 0;
}