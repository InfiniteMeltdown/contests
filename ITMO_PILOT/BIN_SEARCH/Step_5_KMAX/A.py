n, k = map(int, input().split(" "))

segments = []
for i in range(n):
    l, r = map(int, input().split(" "))

    segments.append((l, r))

def count(x):
    result = 0
    for i in range(n):
        l, r = segments[i]

        result += min(r - l + 1, max(x - l, 0))

    return result

l = -int(1e12)
r = int(1e12)
while r - l > 1:
    c = (l + r) // 2

    if count(c) <= k:
        l = c
    else:
        r = c

print(l)