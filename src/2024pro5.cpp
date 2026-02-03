/*#include <iostream>
#include <vector>
#include <unordered_map>

struct Position {
	int row, col;
	// Equality operator required for unordered_map
	bool operator==(const Position& other) const {
		return row == other.row && col == other.col;
	}
};

// Hash function required for unordered_map
namespace std {
	template <> struct hash<Position> {
		int operator()(const Position& p) const {
			return hash<int>{}(p.row) ^ (hash<int>{}(p.col) << 1);
		}
	};
}

std::vector<std::vector<char>> map;
std::unordered_map<Position, bool> checked;

int visitSquare(int row, int col) {
	if (row < 0 || row >= (int)map.size() ||
		col < 0 || col >= (int)map[0].size())
		return 0;


	char cell = map.at(row).at(col);
	if (checked.count({row, col}))
		return 0;

	checked[{row, col}] = true;
	if (cell == 'S')
		return 1;
	if (cell == 'M')
		return 5;
	if (cell == 'L')
		return 10;
	else {
		return 0;
	}
}

//				start position
int checkAll(int row, int col) {
	int score = visitSquare(row, col);

	if (score == 0)
		return 0;

	score += checkAll(row - 1, col);
	score += checkAll(row + 1, col);
	score += checkAll(row, col - 1);
	score += checkAll(row, col + 1);

	return score;
}

int main() {
	int rows = 0; 
	int cols = 0;

	std::cin >> rows;
	std::cin >> cols;

	map.reserve(rows);

	for (int i = 0; i < rows; ++i) {
		std::string line;
		std::cin >> line;

		map.emplace_back(line.begin(), line.end());
	}

	// farmers position
	int posRow = 0; // ~ y
	int posCol = 0; // ~ x

	std::cin >> posRow;
	std::cin >> posCol;

	int score = checkAll(posRow, posCol);

	std::cout << score << "\n";

	return 0;
} */