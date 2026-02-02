/*
#include <iostream>
#include <unordered_map>
#include <map>
#include <iterator>

int main() {
	size_t n;
	std::cin >> n;

	//					num, people
	std::unordered_map<int, int> map;

	for (size_t i = 0; i < n; ++i) {
		int num;
		std::cin >> num;

		map[num] += 1;
	}

	std::map<int, int, std::greater<int>> sortedMap(map.begin(), map.end());

	auto it = std::next(sortedMap.begin(), 2);

	if (it != sortedMap.end()) {
		std::cout << it->first << " " << it->second << "\n";
	}

	return 0;
} // o (n log n) bad */