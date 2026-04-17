/*#include <iostream>

int main() {
	int players;

	std::cin >> players;

	int numPlayers = 0;
	for (int i = 0; i < players; ++i) {
		int total = 0;
		int pointsScored;
		int fouls;

		std::cin >> pointsScored >> fouls;

		total += (pointsScored * 5);
		total -= (fouls * 3);
		
		if (total > 40)
			numPlayers++;
	}

	if (numPlayers == players) {
		std::cout << players << "+" << "\n";
		return 0;
	}

	std::cout << numPlayers << "\n";

	return 0;
}*/