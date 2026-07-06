#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to print the grid
void printGrid(const vector<vector<long long>>& grid) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the grid is entirely valid
bool isValid(const vector<vector<long long>>& g) {
    for (int i = 0; i < 3; i++) {
        if (g[i][2] - g[i][1] != g[i][1] - g[i][0]) return false;
        if (g[2][i] - g[1][i] != g[1][i] - g[0][i]) return false;
    }
    return true;
}

// Fills missing values in rows where two numbers are known
void fillRows(vector<vector<long long>>& g) {
    for (int i = 0; i < 3; i++) {
        if (g[i][0] == -1e18 && g[i][1] != -1e18 && g[i][2] != -1e18) {
            g[i][0] = g[i][1] - (g[i][2] - g[i][1]);
        }
        else if (g[i][1] == -1e18 && g[i][0] != -1e18 && g[i][2] != -1e18) {
            g[i][1] = (g[i][0] + g[i][2]) / 2;
        }
        else if (g[i][2] == -1e18 && g[i][0] != -1e18 && g[i][1] != -1e18) {
            g[i][2] = g[i][1] + (g[i][1] - g[i][0]);
        }
    }
}

// Fills missing values in columns where two numbers are known
void fillCols(vector<vector<long long>>& g) {
    for (int j = 0; j < 3; j++) {
        if (g[0][j] == -1e18 && g[1][j] != -1e18 && g[2][j] != -1e18) {
            g[0][j] = g[1][j] - (g[2][j] - g[1][j]);
        }
        else if (g[1][j] == -1e18 && g[0][j] != -1e18 && g[2][j] != -1e18) {
            g[1][j] = (g[0][j] + g[2][j]) / 2;
        }
        else if (g[2][j] == -1e18 && g[0][j] != -1e18 && g[1][j] != -1e18) {
            g[2][j] = g[1][j] + (g[1][j] - g[0][j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<long long>> grid(3, vector<long long>(3));
    int xCount = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string s;
            cin >> s;
            if (s == "x") {
                grid[i][j] = -1e18; // Use a very small number as a placeholder for 'X'
                xCount++;
            } else {
                grid[i][j] = stoll(s);
            }
        }
    }

    // Repeatedly fill using basic math logic
    for (int k = 0; k < 10; k++) {
        fillRows(grid);
        fillCols(grid);
    }

    // If there is just 1 empty value left, we can calculate it dynamically
    if (xCount == 1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == -1e18) {
                    // Try to deduce via rows and cols
                    fillRows(grid);
                    fillCols(grid);
                }
            }
        }
    }

    printGrid(grid);

    return 0;
}