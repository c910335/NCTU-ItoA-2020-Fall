# TLE
from heapq import heappush, heappop, _heappop_max, _siftdown_max

s = 0
l = []
r = []

n, k = map(int, input().split())
k = 100 - k

for _ in range(n):
    x = int(input())
    if x == 0:
        if len(l) == 0:
            print(r[0])
        else:
            print(l[0])
    else:
        s += 1
        if len(l) == 0 or x <= l[0]:
            l.append(x)
            _siftdown_max(l, 0, len(l) - 1)
            if len(r) < s * k // 100:
                heappush(r, _heappop_max(l))
        else:
            heappush(r, x)
            if len(r) > s * k // 100:
                l.append(heappop(r))
                _siftdown_max(l, 0, len(l) - 1)
