/*
#include <iostream>
#include <vector>

int main() {
	int num = -1;
	std::cin >> num;
	
	std::vector<int> veclin1;
	std::vector<int> veclin2;

	size_t meters = 0;
	for (int i = 0; i < 2; ++i) {
		std::string line;
		std::cin >> line;

		if (i == 0) {
			bool adj = false;
			for (const char& ch : line) {

				if (ch == '0') {
					veclin1.emplace_back(0);
					adj = false;
				}
				else if (ch == '1') {
					veclin1.emplace_back(1);
					meters += 3;

					if (adj == true)
						meters--;

					adj = true;
				}
			}
		}
		if (i == 1) {
			bool adj = false;
			for (const char& ch : line) {

				if (ch == '0') {
					veclin2.emplace_back(0);
					adj = false;
				}
				else if (ch == '1') {
					veclin2.emplace_back(1);
					meters += 3;

					if (adj == true)
						meters--;

					adj = true;
				}
			}
		}
	}

	for (int i = 0; i < veclin1.size(); ++i) {
		if (veclin1.at(i) == 1)
			if (veclin2.at(i) == 1)
				meters--;
	}

	std::cout << meters << "\n";

	return 0;
} */