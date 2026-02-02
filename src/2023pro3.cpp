/*
#include <iostream>
#include <unordered_map>

int main() {
	int num = -1;
	std::cin >> num;
	
	std::unordered_map<int, int> day_map;
	day_map.reserve(5);
	day_map[0] = 0; // day 1
	day_map[1] = 0; // day 2
	day_map[2] = 0; // day 3
	day_map[3] = 0; // day 4
	day_map[4] = 0; // day 5

	for (int i = 0; i < num; ++i) {
		std::string line;
		std::cin >> line;

		for (int j = 0; j < 5; ++j) {
			if (line[j] == 'Y')
				day_map[j]++;
		}
	}

	std::vector<int> vec;
	int winner = -1;
	for (int i = 0; i < 5; ++i) {
		if (winner < day_map[i]) {
			winner = day_map[i];

			vec.clear();
			vec.push_back(i);
		}
		else if (winner == day_map[i]) {
			vec.push_back(i);
		}
	}

	// format (so that it is the 4 day not 3, or the 1 day not day 0)
	const char* separator = "";
	for (int i : vec) {
		std::cout << separator << i + 1;
		separator = ", ";
	}

	return 0;
}*/