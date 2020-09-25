t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = 0
    while n >= k:
        a += n // k
        n = n // k + n % k
    print(a)
