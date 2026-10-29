#include <iostream>
#include <algorithm>
#include <array>
#include <random>

std::array<int, 50> arr;

// Set up the random number engine and range (e.g., 1 to 100)
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> distrib(1, 100);


int main() {
    for (int i = 0; i < 50; ++i) {
        arr[i] = distrib(gen);
    }
    
    int t = 123;
    std::sort(std::begin(arr), std::end(arr));
    int pointer1 = 0; 
    int pointer2 = 49;
    
    int count = 0;
    while (pointer1 < pointer2) {
        count++;
        int combined = arr[pointer1] + arr[pointer2];
        if (combined == t) {
            std::cout << "YES\n";
            std::cout << count;
            return 0;
        } else if (combined < t) {
            pointer1++;
        } else if (combined > t) {
            pointer2--;
        }

        
    }

    std::cout << "NO\n";
    std::cout << count;

    return 0;
}