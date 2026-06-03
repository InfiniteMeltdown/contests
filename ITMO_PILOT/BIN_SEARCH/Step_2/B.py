import math

n, k = map(int, input().split(" "))
a = []
for i in range(n):
    a.append(int(input()))

def can_cut(x):
    total = 0
    for i in range(n):
        total += math.floor(a[i] / x)

    return total >= k

l = 0
r = max(a)
for i in range(100):
    c = (l + r) / 2

    if can_cut(c):
        l = c
    else:
        r = c

print(l)