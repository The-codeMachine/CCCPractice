#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int odd_cnt = 0;
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        if (x % 2) odd_cnt++;
    }

    if (N % 2 == 1) {
        cout << "Steven\n";
    } else {
        if (odd_cnt > N / 2) {
            cout << "Todd\n";
        } else {
            cout << "Steven\n";
        }
    }

    return 0;
}