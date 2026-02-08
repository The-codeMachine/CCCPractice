/*#include <iostream>
#include <vector>
#include <string>
#include <cctype>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> codes;

    while (N--) {
        std::string s;
        std::cin >> s;

        std::string uppercase;
        long long sum = 0;

        long long current = 0;
        int sign = 1;
        bool inNumber = false;

        // sentinel to flush last number
        s.push_back(' ');

        for (size_t i = 0; i < s.size(); ++i) {
            char ch = s[i];

            // uppercase extraction
            if (std::isupper(static_cast<unsigned char>(ch))) {
                uppercase.push_back(ch);
            }

            if (ch == '-') {
                // flush previous number if one was running
                if (inNumber) {
                    sum += sign * current;
                    current = 0;
                    inNumber = false;
                }

                sign = -1;
                current = 0;
                inNumber = true;
            }
            else if (std::isdigit(static_cast<unsigned char>(ch))) {
                if (!inNumber) {
                    sign = 1;
                    current = 0;
                    inNumber = true;
                }

                current = current * 10 + (ch - '0');
            }
            else {
                if (inNumber) {
                    sum += sign * current;
                    current = 0;
                    inNumber = false;
                    sign = 1;
                }
            }
        }

        codes.push_back(uppercase + std::to_string(sum));
    }

    for (const std::string& line : codes)
        std::cout << line << "\n";

    return 0;
}
*/