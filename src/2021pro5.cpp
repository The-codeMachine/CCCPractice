/*#include <iostream>
#include <vector>

void changeRow(int index, std::vector<std::vector<int>>& painting) {
	for (int i = 0; i < painting[index].size(); ++i) {
		if (painting[index][i] == 1) { // gold
			painting[index][i] = 0;
		}
		else if (painting[index][i] == 0) { // black
			painting[index][i] = 1;
		}
	}
}

void changeCol(int index, std::vector<std::vector<int>>&  painting) {
	for (int i = 0; i < painting.size(); ++i) {
		if (painting[i][index] == 1) { // gold
			painting[i][index] = 0;
		}
		else if (painting[i][index] == 0) {
			painting[i][index] = 1;
		}
	}
}

int main() {
	int rows, cols;
	std::cin >> rows >> cols;

	// rows		col			1 if gold
	std::vector<std::vector<int>> canvas(rows, std::vector<int>(cols, 0));

	int k;
	std::cin >> k;

	while (k--) {
		char type;
		int number;
		std::cin >> type >> number;

		if (type == 'R') // row 
			changeRow(number - 1, canvas);
		else if (type == 'C') // col 
			changeCol(number - 1, canvas);
	}

	int num = 0;
	for (std::vector<int> vec : canvas) {
		for (int i : vec) {
			if (i == 1) {
				num++;
			}
		}
	}

	std::cout << num << "\n";

	return 0;
}*/