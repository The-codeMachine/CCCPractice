#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct pair {
	std::string studentOne;
	std::string studentTwo;
};

int main() {
	int x; // must be together

	std::cin >> x;
	
	std::vector<pair> mustBeTogether;
	while (x--) {
		std::string group;
		std::cin >> group;

		std::istringstream iss(group);
		std::string token;
		pair pairOfStudents;
		while (iss >> token) {
			if (pairOfStudents.studentOne == "")
				pairOfStudents.studentOne = token;
			else if (pairOfStudents.studentTwo == "") {
				pairOfStudents.studentTwo = token;
				mustBeTogether.push_back(pairOfStudents);
				pairOfStudents = pair{};
			}
		}
	}

	int y; // cannot be together

	std::cin >> y;
	
	std::vector<pair> mustBeTogether;
	while (y--) {
		std::string group;
		std::cin >> group;

		std::istringstream iss(group);
		std::string token;
		pair pairOfStudents;
		while (iss >> token) {
			if (pairOfStudents.studentOne == "")
				pairOfStudents.studentOne = token;
			else if (pairOfStudents.studentTwo == "") {
				pairOfStudents.studentTwo = token;
				mustBeTogether.push_back(pairOfStudents);
				pairOfStudents = pair{};
			}
		}
	}

	int idk;

	std::cin >> idk;

	for (int i = 0; i < idk; ++i) {

	}

	return 0;
}