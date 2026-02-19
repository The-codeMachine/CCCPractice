/*#include <iostream>
#include <vector>

int main() {
	std::string booksStr;
	std::cin >> booksStr;

	std::vector<int> books;
	books.reserve(booksStr.size());

	for (const char& ch : booksStr) {
		if (ch == 'L')
			books.push_back(3);
		else if (ch == 'M')
			books.push_back(2);
		else if (ch == 'S')
			books.push_back(1);
	}

	size_t swaps = 0;

	for (int i = 0; i < books.size() - 1; i++) {
		for (int j = 0; j < books.size() - i - 1; j++) {
			if (books[j] < books[j + 1]) {
				int temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;

				swaps++;
			}
		}
	}

	std::cout << swaps << "\n";

	return 0;
}*/