from functools import reduce
input()
print(reduce(int.__xor__, map(int, input().split())))
