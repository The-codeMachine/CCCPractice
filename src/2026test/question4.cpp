#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string nLine, mLine;
    std::cin >> nLine >> mLine;

    size_t i = 0, j = 0;
    int nCandiesConsumed = 0;
    int mCandiesConsumed = 0;

    while (i < nLine.size() && j < mLine.size())
    {
        char a = nLine[i];
        char b = mLine[j];

        if (a == b)
        {
            ++nCandiesConsumed;
            ++mCandiesConsumed;
            ++i;
            ++j;
        }
        else
        {
            // Direct comparison logic instead of map
            if ((a == 'R' && b == 'G') ||
                (a == 'G' && b == 'B') ||
                (a == 'B' && b == 'R'))
            {
                ++j;
                ++nCandiesConsumed;
            }
            else
            {
                ++i;
                ++mCandiesConsumed;
            }
        }
    }

    // Add remaining
    nCandiesConsumed += (nLine.size() - i);
    mCandiesConsumed += (mLine.size() - j);

    std::cout << nCandiesConsumed << "\n"
              << mCandiesConsumed << "\n";

    return 0;
}