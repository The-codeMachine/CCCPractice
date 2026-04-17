/*#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

int main() {
    std::string pressed, displayed;
    std::cin >> pressed >> displayed;

    std::vector<int> inPressed(26, 0);
    std::vector<int> inDisplayed(26, 0);

    for (char c : pressed) inPressed[c - 'a']++;
    for (char c : displayed) inDisplayed[c - 'a']++;

    char wrong = '-';
    for (int i = 0; i < 26; ++i) {
        if (inDisplayed[i] > 0 && inPressed[i] == 0) {
            wrong = char('a' + i);
            break;
        }
    }

    std::vector<char> candidates;
    for (int i = 0; i < 26; ++i) {
        if (inPressed[i] > 0 && inDisplayed[i] == 0) {
            candidates.push_back(char('a' + i));
        }
    }

    char silly = '-';
    char quiet = '-';

    for (char s : candidates) {
        for (char q : candidates) {
            if (s == q) continue;

            std::string sim;

            for (char c : pressed) {
                if (c == q) continue;
                if (c == s) sim.push_back(wrong);
                else sim.push_back(c);
            }

            if (sim == displayed) {
                silly = s;
                quiet = q;
                break;
            }
        }
        if (silly != '-') break;
    }

    if (silly == '-') {
        for (char s : candidates) {
            std::string sim;

            for (char c : pressed) {
                if (c == s) sim.push_back(wrong);
                else sim.push_back(c);
            }

            if (sim == displayed) {
                silly = s;
                quiet = '-';
                break;
            }
        }
    }

    std::cout << silly << " " << wrong << "\n";
    std::cout << quiet << "\n";
} */