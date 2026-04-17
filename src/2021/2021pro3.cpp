/*#include <iostream>
#include <vector>

int main() {
	std::string num;

	std::vector<std::string> results;

	while (true) {
		std::cin >> num;
		std::string final;

		if (num == "99999")
			break;

		if (((num[0] + num[1]) % 2) == 0) {
			final += "right ";
		}
		else {
			final += "left ";
		}

		final.push_back(num[2]);
		final.push_back(num[3]);
		final.push_back(num[4]);
		results.push_back(final);
	}

	for (std::string str : results)
		std::cout << str << "\n";

	return 0;
}*/