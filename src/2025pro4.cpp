#include <iostream>
#include <vector>

int main() {
	size_t days;
	std::cin >> days;

	size_t currentBest = 0;
	std::vector<bool> forecast;
	for (size_t i = 0; i < days; ++i) {
		char input;
		std::cin >> input;

		forecast.push_back(input != 'P'); // true == Sunny
	}

	size_t longestSunny = 0;
	size_t current = 0;

	for (bool day : forecast) {
		if (day) {
			++current;
			longestSunny = std::max(longestSunny, current);
		}
		else {
			current = 0;
		}
	}

	for (size_t i = 0; i < forecast.size(); ++i) {
		if (forecast[i]) // sunny
			continue;

		// must be precipitation
		size_t theory = 0;
		size_t left = i;
		while (left > 0 && forecast[left - 1]) {
			--left;
			++theory;
		}

		// look right
		size_t right = i;
		while (right + 1 < forecast.size() && forecast[right + 1]) {
			++right;
			++theory;
		}

		++theory; // count itself

		if (currentBest < theory)
			currentBest = theory;
	}

	std::cout << currentBest << "\n";

	return 0;
}