from math import sqrt

c = float(input())

l = 0
r = 100000000
for i in range(100):
    mid = (l + r) / 2

    if mid ** 2 + sqrt(mid) < c:
        l = mid
    else:
        r = mid

print(l)