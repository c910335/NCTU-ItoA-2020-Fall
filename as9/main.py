# TLE
n, m = map(int, input().split())
a = [0] + list(map(int, input().split()))
b = [0] * (n + 1)
for i in range(1, n + 1):
    b[i] += a[i]
    j = i + (i & -i)
    if (j <= n):
        b[j] += b[i]

for _ in range(m):
    i, j, k = map(int, input().split())
    if i == 0:
        j += 1
        k -= a[j]
        a[j] += k
        while j <= n:
            b[j] += k
            j += j & -j
    else:
        s = 0
        if j > k:
            i = n
            while i > 0:
                s += b[i]
                i &= i - 1
        while j > 0:
            s -= b[j]
            j &= j - 1
        k += 1
        while k > 0:
            s += b[k]
            k &= k - 1
        print(s)
