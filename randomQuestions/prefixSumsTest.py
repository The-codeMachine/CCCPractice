import random
import sys

N = 10
M = 20
Q = 20

print(N, M, Q)

a = [0] * N

for _ in range(M):
    l = random.randint(1, N)
    r = random.randint(l, N)
    v = random.randint(-10, 10)
    print(l, r, v)
    for i in range(l - 1, r):
        a[i] += v

pref = a[:]
for i in range(1, N):
    pref[i] += pref[i - 1]

for _ in range(Q):
    l = random.randint(1, N)
    r = random.randint(l, N)
    print(l, r)
    ans = pref[r - 1] - (pref[l - 2] if l > 1 else 0)
    print(ans, file=sys.stderr)