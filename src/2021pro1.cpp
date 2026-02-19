#include <iostream>

int main() {
	int b; 
	std::cin >> b;

	int num = 5 * b - 400;
	std::cout << num << "\n";

	if (num < 100)
		std::cout << "1\n";

	else if (num > 100)
		std::cout << "-1\n";

	else
		std::cout << "0\n";



	return 0;
}