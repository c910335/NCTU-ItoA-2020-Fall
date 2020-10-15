# TLE
from heapq import _heappop_max, _siftdown_max, _heapify_max

n = int(input())
h = list(map(int, input().split()))
h.append(0)
_heapify_max(h)
c = 0

while len(h) > 1:
    a = h[0]
    _heappop_max(h)
    a -= h[0]
    _heappop_max(h)
    if a != 0:
        c += a
        h.append(a)
        _siftdown_max(h, 0, len(h) - 1)

print(c)
