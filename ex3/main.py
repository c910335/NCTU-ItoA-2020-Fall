n, t = map(int, input().split())
a = list(map(int, input().split()))

d = {}
c = 0

for v in a:
    if t - v in d:
        c += d[t - v]
    if v in d:
        d[v] += 1
    else:
        d[v] = 1

print(c)
