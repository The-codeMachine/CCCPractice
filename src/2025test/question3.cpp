#include <iostream>
#include <vector>
#include <string>

int getNumber(const std::string &line)
{
    std::vector<int> numbers;
    std::string currentNumber;

    for (int i = 0; i < line.size(); ++i)
    {
        if (std::isdigit(line[i]))
        {
            if (i - 1 > 0)
            {
                if (line[i - 1] == '-')
                    currentNumber = "-";
            }

            currentNumber += line[i];

            if (i == line.size() - 1)
            {
                numbers.push_back(std::stoi(currentNumber));
            }
        }
        else
        {
            if (!currentNumber.empty())
            {
                numbers.push_back(std::stoi(currentNumber));
                currentNumber = "";
            }
        }
    }

    int finalNumber = 0;

    for (int i : numbers)
    {
        finalNumber += i;
    }

    return finalNumber;
}

int main()
{
    size_t codes;
    std::cin >> codes;

    std::vector<std::string> updatedCodes;
    while (codes--)
    {
        std::string code;
        std::cin >> code;

        std::string updatedCode;
        int number = 0;
        for (const char &ch : code)
        {
            if (std::isupper(ch))
                updatedCode += ch;
        }

        updatedCode += std::to_string(getNumber(code));
        updatedCodes.push_back(updatedCode);
    }

    for (std::string code : updatedCodes)
    {
        std::cout << code << "\n";
    }

    return 0;
}