/*#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string pressed, displayed;
    cin >> pressed >> displayed;

    // Store unique letters from each string
    set<char> pset;
    for (char c : pressed) pset.insert(c);

    set<char> dset;
    for (char c : displayed) dset.insert(c);

    // 1) Find the wrong letter (appears in displayed but not pressed)
    char wrong = '?';
    for (char c : dset) {
        if (pset.find(c) == pset.end()) {
            wrong = c;
            break;
        }
    }

    // 2) Find candidates for silly/quiet keys
    vector<char> candidates;
    for (char c : pset) {
        if (dset.find(c) == dset.end()) {
            candidates.push_back(c);
        }
    }

    char silly = '?';
    char quiet = '-';

    // Function to simulate the typing
    auto works = [&](char sillyTry, char quietTry) {
        string sim;
        for (char c : pressed) {
            if (c == sillyTry) {
                sim.push_back(wrong);
            }
            else if (c == quietTry) {
                // produces nothing
            }
            else {
                sim.push_back(c);
            }
        }
        return sim == displayed;
        };

    // Try possible assignments
    for (char c : candidates) {
        char other = '-';
        if (candidates.size() == 2) {
            if (candidates[0] == c)
                other = candidates[1];
            else
                other = candidates[0];
        }

        if (works(c, other)) {
            silly = c;
            quiet = other;
            break;
        }
    }

    // Output results
    cout << silly << " " << wrong << "\n";
    if (quiet == '-')
        cout << "-\n";
    else
        cout << quiet << "\n";

    return 0;
}
*/