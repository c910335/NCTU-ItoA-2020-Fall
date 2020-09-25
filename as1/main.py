MOD = 10**9 + 7
t = int(input())

def m(c):
    c[0] %= MOD
    c[1] %= MOD

def x(a, b):
    t = []
    t.append(a[0] * b[0] - a[1] * b[1])
    t.append(a[0] * b[1] + a[1] * b[0])
    return t

def p(c, n):
    m(c)
    if n == 1:
        return c
    t = p(x(c, c), n // 2)
    if n & 1 == 1:
        t = x(t, c)
    m(t)
    return t

for _ in range(t):
    a, b, n = map(int, input().split())
    if (n == 0):
        print("1 0")
    else:
        c = p([a, b], n)
        print(f"{c[0]} {c[1]}")
