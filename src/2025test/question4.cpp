#include <iostream>
#include <vector>

size_t simulateDayChange(const std::vector<char> &days, const size_t &index)
{
    std::vector<char> updatedDays = days;

    if (updatedDays[index] == 'P')
    {
        updatedDays[index] = 'S';
    }
    else if (updatedDays[index] == 'S')
    {
        updatedDays[index] = 'P';
    }

    size_t longestStreak = 0;
    size_t currentStreak = 0;
    for (size_t i = 0; i < updatedDays.size(); ++i)
    {
        if (updatedDays[i] == 'S')
            currentStreak++;
        else if (updatedDays[i] == 'P')
        {
            if (currentStreak > longestStreak)
            {
                longestStreak = currentStreak;
            }

            currentStreak = 0;
        }
    }

    return longestStreak;
}

int main()
{
    size_t numDays;
    std::cin >> numDays;

    std::vector<char> days;
    while (numDays--)
    {
        char day;
        std::cin >> day;

        days.push_back(day);
    }

    size_t longestStreak = 0;
    for (size_t i = 0; i < days.size(); ++i)
    {
        size_t currentStreak = simulateDayChange(days, i);

        if (currentStreak > longestStreak)
        {
            longestStreak = currentStreak;
        }
    }

    std::cout << longestStreak << "\n";

    return 0;
}