#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

std::vector<int> a;
std::unordered_map<int, int> map;
int N = 0;
int Q = 0;

void update(int i, int x) {
    static int index = N - 1;
    if (index >= i && index <= i) {
        int v = a[i];
        a[i] = x;

        map[v] -= 1;
        map[x] += 1;
    }
}

int query(int l, int r) {
    int domaintValue = std::floor((r - l + 1) / 2);
    int ll = l - 1;

    for (int i = ll; i < r; ++i) {
        int v = map[a[i]];

        if (v >= domaintValue)
            return a[i];
    }

    return -1;
}

int main() {
    std::cin >> N >> Q;

    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;

        a.push_back(num);
        map[num] += 1;
    }

    while (Q--) {
        int op;
        std::cin >> op;
        
        if (op == 1) {
            int a, b;
            std::cin >> a >> b;
            
            update(a, b);
        } else {
            int l, r;
            std::cin >> l >> r;

            std::cout << query(l, r) << "\n";
        }
    }

    return 0;
}