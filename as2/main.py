def f(l, r):
    global a
    if l + 1 >= r:
        return
    m = (l + r) // 2
    s = m - l
    f(l, m)
    f(m, r)

    t = a[l:m]
    i = l
    j = 0
    k = m

    while True:
        if t[j][0] <= a[k][0]:
            a[i] = t[j]
            a[i][2] += k - m
            i += 1
            j += 1
            if j == s:
                break
        else:
            a[i] = a[k]
            a[i][1] += s - j
            i += 1
            k += 1
            if k == r:
                break
    while j != s:
        a[i] = t[j]
        a[i][2] += k - m
        i += 1
        j += 1

n = int(input())
a = [[v, 0, 0] for v in map(int, input().split())]

f(0, n)

c = 0
for _, l, r in a:
    c += l * r
print(c)
