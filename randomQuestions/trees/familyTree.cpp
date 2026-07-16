#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> children(N);
    N--;
    children[0].first = 0;
    for (int i = 0; i < N; ++i) {
        int P, C;
        std::cin >> P >> C;

        P--; C--;

        children[C].first = children[P].first + 1;
        children[C].second = P;
    }
    
    for (int i = 1; i < N; ++i) {
        children[i].first = children[children[i].second].first + 1;
    }
    
    N++;
    int biggest = 0;
    for (int i = 0; i < N; ++i) {
        if (children[i].first > biggest)
            biggest = children[i].first;
    }

    std::cout << biggest << "\n";

    return 0;
}