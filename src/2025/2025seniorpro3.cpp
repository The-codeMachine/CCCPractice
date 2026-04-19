#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void remove_colour(
    multiset<int>& ms,
    multiset<int>& best,
    multiset<int>& others,
    long long& T
) {
    if (ms.empty()) return;

    auto it = prev(ms.end());
    int mx = *it;

    best.erase(best.find(mx));
    T -= mx;

    for (auto jt = ms.begin(); jt != it; ++jt)
        others.erase(others.find(*jt));
}

void add_colour(
    multiset<int>& ms,
    multiset<int>& best,
    multiset<int>& others,
    long long& T
) {
    if (ms.empty()) return;

    auto it = prev(ms.end());
    int mx = *it;

    best.insert(mx);
    T += mx;

    if (ms.size() >= 2) {
        auto it2 = prev(ms.end(), 2);
        others.insert(*it2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> colour(n), value(n);

    unordered_map<int, multiset<int>> colours;

    for (int i = 0; i < n; ++i) {
        cin >> colour[i] >> value[i];
        colours[colour[i]].insert(value[i]);
    }

    multiset<int> best, others;
    long long T = 0;

    // initial build
    for (auto& [c, ms] : colours) {
        add_colour(ms, best, others, T);
    }

    auto get_answer = [&]() {
        long long ans = T;
        if (!others.empty()) {
            ans = max(T,
                T - *best.begin() + *prev(others.end()));
        }
        return ans;
    };

    cout << get_answer() << "\n";

    while (q--) {
        int i, x;
        cin >> i >> x;
        --i;

        int c = colour[i];

        // remove old contribution
        remove_colour(colours[c], best, others, T);

        // erase old value
        colours[c].erase(colours[c].find(value[i]));

        // insert new value
        value[i] = x;
        colours[c].insert(x);

        // add updated contribution
        add_colour(colours[c], best, others, T);

        cout << get_answer() << "\n";
    }
}