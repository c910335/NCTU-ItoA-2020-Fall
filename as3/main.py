from math import exp

t = int(input())
for _ in range(t):
    y = int(input())
    l = 0.0
    r = 20.0
    while r - l >= 1e-9:
        m = (l + r) / 2
        if m * exp(m) < y:
            l = m
        else:
            r = m
    print((l + r) / 2)
