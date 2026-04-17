#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

int main()
{
    std::string expected;
    std::string displayed;

    std::cin >> expected >> displayed;

    std::unordered_map<char, int> expectedChars;
    std::unordered_map<char, int> displayedChars;

    for (const char &ch : expected)
    {
        expectedChars[ch] += 1;
    }

    for (const char &ch : displayed)
    {
        displayedChars[ch] += 1;
    }

    // loop through the expected chars, and see if they exist inside the displayed, gather all of the ones that do not
    std::set<char> notDisplayed;
    //             original  replacement
    std::set<std::pair<char, char>> possibleReplacements;

    for (auto [key, value] : expectedChars)
    {
        if (displayedChars.count(key) == 0)
        {
            notDisplayed.insert(key);
        }

        for (auto [keyD, valueD] : displayedChars)
        {
            if (expectedChars.count(key) == 1 && displayedChars.count(key) == 1 && valueD != value)
            {
                possibleReplacements.insert({key, keyD});
            }

            if ((valueD == value) && !(displayedChars.count(key) == 0 && expectedChars.count(keyD) == 1))
            {
                possibleReplacements.insert({key, keyD});
            }
        }
    }

    std::pair<char, char> output = {'-', '-'};
    char silent = '-';
    for (const auto &pair : possibleReplacements)
    {
        if (pair.first == pair.second)
            continue;

        for (const char &ch : notDisplayed)
        {
            if (ch == pair.first)
            {
                // must be the replacement
                output.first = pair.first;
                output.second = pair.second;

                possibleReplacements.erase({pair.first, pair.second});

                break;
            }
            else if (output.first != pair.first && output.first != ch && output.first != '-')
            {
                silent = ch;
            }
        }

        if (output.first != '-')
            break;
    }

    if (silent == '-')
    {
        for (const auto &pair : possibleReplacements)
        {
            if (pair.first == pair.second)
                continue;

            for (const char &ch : notDisplayed)
            {
                if (ch == pair.first)
                {
                    // must be the replacement
                    output.first = pair.first;
                    output.second = pair.second;

                    possibleReplacements.erase({pair.first, pair.second});

                    break;
                }
                else if (output.first != pair.first && output.first != ch && output.first != '-')
                {
                    silent = ch;
                }
            }

            if (silent != '-')
                break;
        }
    }

    std::cout << output.first << " " << output.second << "\n";
    std::cout << silent << "\n";

    return 0;
}