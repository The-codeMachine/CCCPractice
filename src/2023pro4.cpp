#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	size_t cols;
	std::cin >> cols;
	std::cin.ignore(); // discared newline after col

	std::string row1, row2;

	std::getline(std::cin, row1);
	std::getline(std::cin, row2);

	// Remove spaces
	row1.erase(std::remove(row1.begin(), row1.end(), ' '), row1.end());
	row2.erase(std::remove(row2.begin(), row2.end(), ' '), row2.end());

	size_t meters = 0;
	bool isAdjecent1 = false;
	bool isAdjecent2 = false;
	for (size_t i = 0; i < row1.size(); ++i) {
		if (row1[i] == '1' && row2[i] == '1') {
			meters += 4;
			isAdjecent1 = true;
			isAdjecent2 = true;

			if (row1[i - 1] == '1' && row1[i + 1] == '1' || row2[i - 1] == '1' && row2[i + 1] == '1') {
				meters -= 2;
			}
			continue;
		}

		if (row1[i] == '1' && isAdjecent1 == false) {
			isAdjecent1 = true;
			meters += 3;
		}
		else if (row1[i] == '1' && isAdjecent1 == true) {
			meters++;
		}
		else {
			isAdjecent1 = false;
		}

		if (row2[i] == '1' && isAdjecent2 == false) {
			isAdjecent2 = true;
			meters += 3;
		}
		else if (row2[i] == '1' && isAdjecent2 == true) {
			meters++;
		}
		else {
			isAdjecent2 = false;
		}
	}

	std::cout << meters << "\n";

	return 0;
} 