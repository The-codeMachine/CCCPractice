#include <bits/stdc++.h>
using namespace std;

bitset<2000006> isNotPrime;
vector<int> primes;

void Seive()
{
    primes.push_back(2);
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;

    for (int i = 4; i <= 2000000; i += 2)
        isNotPrime[i] = 1;

    for (int64_t i = 3; i <= 2000000; i += 2)
    {
        if (isNotPrime[i] == 0)
        {
            primes.push_back(i);
            for (int64_t j = i * i; j <= 2000000; j += 2 * i)
                isNotPrime[j] = 1;
        }
    }
}

void Solution()
{
    int N;
    cin >> N;

    int sum = 2 * N;

    for (int p : primes)
    {
        if (isNotPrime[sum - p] == 0)
        {
            cout << p << ' ' << sum - p << '\n';
            return;
        }
    }
}

int main()
{
    Seive();
    int test;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        Solution();
    }

    return 0;
}