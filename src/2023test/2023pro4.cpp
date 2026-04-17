#include <iostream>
#include <vector>
#include <string>

int main()
{
    size_t length;
    std::cin >> length;

    std::vector<bool> trisRow1;
    std::vector<bool> trisRow2;

    for (int j = 0; j < length; j++)
    {
        int i;
        std::cin >> i;

        if (i == 1)
            trisRow1.push_back(true);
        else if (i == 0)
            trisRow1.push_back(false);
    }
    for (int j = 0; j < length; j++)
    {
        int i;
        std::cin >> i;

        if (i == 1)
            trisRow2.push_back(true);
        else if (i == 0)
            trisRow2.push_back(false);
    }

    size_t tapeLength = 0;
    bool adj = false;
    for (int i = 0; i < trisRow1.size(); ++i)
    {
        if (adj && trisRow1[i] == true)
        {
            tapeLength++;
        }
        else if (!adj && trisRow1[i] == true)
        {
            adj = true;
            tapeLength += 3;
        }

        if (trisRow1[i] == false)
        {
            adj = false;
        }
    }

    adj = false;
    for (int i = 0; i < trisRow2.size(); ++i)
    {
        if (adj && trisRow2[i] == true)
        {
            tapeLength++;
        }
        else if (!adj && trisRow2[i] == true)
        {
            adj = true;
            tapeLength += 3;
        }

        if (i % 2 == 0)
        {
            if (trisRow1[i] == true && trisRow2[i] == true)
            {
                tapeLength -= 2;
            }
        }

        if (trisRow2[i] == false)
        {
            adj = false;
        }
    }

    std::cout << tapeLength << "\n";

    return 0;
}