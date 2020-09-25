n = int(input())
a = [0] * n
l = 0
r = 0

for i in range(n):
    a[i] = len(input())
    if l < a[i] - 1:
        l = a[i] - 1
    r += a[i]

while l + 1 < r:
    m = (l + r) // 2
    t = -1
    c = 1
    for v in a:
        if t + v + 1 > m:
            c += 1
            t = v
            if c > 24:
                break
        else:
            t += v + 1
    if c > 24:
        l = m
    else:
        r = m

print(r)

