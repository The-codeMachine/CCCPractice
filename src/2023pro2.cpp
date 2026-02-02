/*
#include <iostream>
#include <unordered_map>

int main() {
	int num;

	std::cin >> num;
	std::unordered_map<std::string, size_t> chilies;
	chilies.reserve(num);

	chilies["Poblano"] = 1500;
	chilies["Mirasol"] = 6000;
	chilies["Serrano"] = 15500;
	chilies["Cayenne"] = 40000;
	chilies["Thai"] = 75000;
	chilies["Habanero"] = 125000;

	size_t heat = 0;

	for (int i = 0; i < num; ++i) {
		std::string chili;
		std::cin >> chili;

		heat += chilies[chili];
	}

	std::cout << heat << "\n";

	return 0;
} */