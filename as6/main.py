# TLE
def merge(p, l, r):
    p[0] = max(l[1] + r[0], l[0] + r[2])
    p[1] = max(l[1] + r[1], l[0] + r[3])
    p[2] = max(l[2] + r[2], l[3] + r[0])
    p[3] = max(l[3] + r[1], l[2] + r[3])

def update(x):
    global st
    merge(st[x], st[x << 1], st[(x << 1) + 1])

n, m = map(int, input().split())
st = [[0] * 4 for _ in range(n)] + [[0, 0, 0, a] for a in map(int, input().split())]

for i in reversed(range(n)):
    update(i)

for _ in range(m):
    i, j, k = map(int, input().split())
    j += n
    if i == 0:
        st[j][3] = k
        while j > 1:
            j >>= 1
            update(j)
    else:
        k += n + 1
        l = [0] * 4
        r = [0] * 4
        while j < k:
            if j & 1 == 1:
                t = l[:]
                merge(l, t, st[j])
                j += 1
            if k & 1 == 1:
                k -= 1
                t = r[:]
                merge(r, st[k], t)
            j >>= 1
            k >>= 1
        t = l[:]
        merge(l, t, r)
        print(l[3])
