#include <iostream>
#include <vector>
#include <algorithm>

struct Interval
{
    int left;
    int right;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int numberOfParkingSpots;
    std::cin >> numberOfParkingSpots;

    int numOfLights, parkingLotQuestions;
    std::cin >> numOfLights >> parkingLotQuestions;

    std::vector<Interval> intervals;
    intervals.reserve(numOfLights);

    int location, spread;

    while (numOfLights--)
    {
        std::cin >> location >> spread;
        intervals.push_back({location - spread, location + spread});
    }

    // Sort intervals
    std::sort(intervals.begin(), intervals.end(),
              [](const Interval &a, const Interval &b)
              {
                  return a.left < b.left;
              });

    // Merge intervals
    std::vector<Interval> merged;
    for (const auto &current : intervals)
    {
        if (merged.empty() || merged.back().right < current.left)
        {
            merged.push_back(current);
        }
        else
        {
            merged.back().right = std::max(merged.back().right, current.right);
        }
    }

    // Answer queries
    while (parkingLotQuestions--)
    {
        std::cin >> location;

        // Binary search for interval containing location
        int left = 0, right = merged.size() - 1;
        bool found = false;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (merged[mid].left <= location && location <= merged[mid].right)
            {
                found = true;
                break;
            }
            else if (location < merged[mid].left)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        std::cout << (found ? "Y\n" : "N\n");
    }

    return 0;
}