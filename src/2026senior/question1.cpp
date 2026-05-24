#include <iostream>
#include <cstdint>

int main()
{
    long long a, b, k;
    std::cin >> a >> b >> k;

    int t;
    std::cin >> t;

    // lowest number of jumps
    if (t == 1)
    {

        long long curPos = a;
        size_t numOfJumps = 0;
        if (b < a)
        {
            long long temp = b;
            b = a;
            a = temp;
            curPos = a;
        }

        numOfJumps += (b - curPos) / k;
        curPos = b - (b - curPos) % k;
        if (curPos + k - b + 1 < b - curPos)
        {
            numOfJumps += curPos + k + 1 - b;
            curPos = b;
        }
        else
        {
            numOfJumps += b - curPos;
            curPos = b;
        }

        std::cout << numOfJumps << "\n";
        return 0;
    }
    else
    {
        long long curPos = a;
        size_t numOfJumps = 0;
        if (b < a)
        {
            long long temp = b;
            b = a;
            a = temp;
            curPos = a;
        }

        numOfJumps += (b - curPos) / k;
        curPos = b - (b - curPos) % k;
        if (curPos == b)
        {
            numOfJumps =- 1;
            numOfJumps += k;

            std::cout << numOfJumps << "\n";
            return 0;
        }

        if (curPos + k - b + 1 < b - curPos)
        {
            numOfJumps += b - curPos;
            curPos = b;
        }
        else
        {
            numOfJumps += curPos + k + 1 - b;
            curPos = b;
        }

        std::cout << numOfJumps << "\n";
        return 0;
    }

    return 0;
}