/*#include <iostream>
#include <string>
#include <regex>

int main() {
	std::string tuningInstructions;

	std::cin >> tuningInstructions;

	std::string instruction = "";
	for (int i = 0; i < tuningInstructions.size(); ++i) {
		if (tuningInstructions[i] == '+') {
			std::string copy = tuningInstructions;
			std::string tempNum;

			for (char ch : copy.substr(i)) {
				if (std::isdigit(ch))
					tempNum.push_back(ch);
				else if (tempNum.empty())
					continue;
				else
					break;
			}

			std::cout << instruction << " tighten " << tempNum << "\n";
			instruction = "";
			continue;
		}
		if (tuningInstructions[i] == '-') {
			std::string copy = tuningInstructions;
			std::string tempNum;

			for (char ch : copy.substr(i)) {
				if (std::isdigit(ch))
					tempNum.push_back(ch);
				else if (tempNum.empty())
					continue;
				else
					break;
			}

			std::cout << instruction << " loosen " << tempNum << "\n";
			instruction = "";
			continue;
		}

		if (std::isdigit(tuningInstructions[i]))
			continue;

		instruction.push_back(tuningInstructions[i]);
	}

	return 0;
}*/