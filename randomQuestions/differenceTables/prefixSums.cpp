#include <iostream>
#include <vector>
#include <cstdint>

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<int> diff(n);

    for (int i = 0; i < m; ++i) {
        int l, r, v;
        std::cin >> l >> r >> v;

        l--; 

        diff[l] += v;
        if (r < n)
            diff[r] -= v;
    }

    std::vector<long long> res(n);
    res[0] += diff[0];
    for (int i = 1; i < n; ++i) {
        diff[i] += diff[i - 1];
        res[i] += diff[i];
    }

    for (int i = 1; i < n; ++i) {
        res[i] += res[i - 1];
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        std::cin >> a >> b;

        a--; b--;
        long long answer = res[b] - (a ? res[a - 1] : 0);

        std::cout << answer << "\n";
    }

    return 0;
}