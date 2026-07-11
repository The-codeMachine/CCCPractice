#include <iostream>
#include <vector>

int main() {
    int r, c;
    std::cin >> r >> c;

    int n = r * c;

    int k;
    std::cin >> k; 

    int q;
    std::cin >> q;

    std::vector<long> diff(n, 0);
    for (int i = 0; i < k; ++i) {
        int x, y, xx, yy;
        long v;

        // because the row is the y and the x is the column
        std::cin >> y >> x >> yy >> xx >> v;

        x--; y--; xx--; yy--;

        for (int j = y; j <= yy; ++j) {
            int g = j * c;
            diff[g + x] += v;

            if (g + xx < n)
                diff[g + xx] -= v;
        }
    }

    std::vector<long long> res(n, 0);
    res[0] = diff[0];
    for (int i = 1; i < n; ++i) {
        diff[i] += diff[i - 1];
        res[i] += diff[i];
    }

    for (int i = 1; i < n; ++i) {
        res[i] += res[i - 1];
    }

    for (int i = 0; i < q; ++i) {
        int x, y, xx, yy;
        std::cin >> y >> x >> yy >> xx;

        x--; y--; xx--; yy--;

        long long answer = 0;
        for (int j = y; j <= yy; ++j) {
            int g = j * c;
            answer += res[g + xx] - (g + x ? res[g + x - 1] : 0);
        }

        std::cout << answer << "\n";
    }

    return 0;
}