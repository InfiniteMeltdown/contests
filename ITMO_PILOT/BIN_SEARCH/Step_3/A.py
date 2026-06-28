n = int(input())

x = [0] * n
v = [0] * n

for i in range(n):
    xi, vi = map(int, input().split(" "))

    x[i] = xi
    v[i] = vi

def intersect(t):
    left = x[0] - t * v[0]
    right = x[0] + t * v[0]

    for i in range(1, n):
        left = max(left, x[i] - t * v[i])
        right = min(right, x[i] + t * v[i])

    return left < right

l = 0
r = 1e10
for _ in range(100):
    c = (l + r) / 2

    if intersect(c):
        r = c
    else:
        l = c

print(r)