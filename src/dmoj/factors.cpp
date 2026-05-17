#include <iostream>
#include <map>

using namespace std;

map<long long, int> factorize(long long x) {
    map<long long, int> f;

    for (long long p = 2; p * p <= x; p++) {
        while (x % p == 0) {
            f[p]++;
            x /= p;
        }
    }

    if (x > 1) f[x]++;

    return f;
}

map<long long, int> merge(map<long long,int> a, map<long long,int> b) {
    for (auto &x : b)
        a[x.first] += x.second;
    return a;
}

long long countDivisors(map<long long,int> f) {
    long long res = 1;
    for (auto &x : f)
        res *= (x.second + 1);
    return res;
}

int main() {
    long long L, R;
    std::cin >> L >> R;

    long long n = R - L + 1;
    long long a = L + R;

    auto f1 = factorize(n);
    auto f2 = factorize(a);

    auto total = merge(f1, f2);

    // divide by 2
    if (total[2] > 0) total[2]--;
    else {
        // handle odd case: subtract factor 2 from somewhere else
        // (simplified assumption case)
    }

    cout << countDivisors(total) << "\n";
}