n, k = map(int, input().split(" "))

def count(x):
    result = 0
    for i in range(n):
        delta = x // (i + 1)
        if x % (i + 1) == 0:
            delta -= 1

        result += min(n, delta)

    return result

l = 1
r = n ** 2 + 1
while r - l > 1:
    c = (l + r) // 2

    if count(c) <= k - 1:
        l = c
    else:
        r = c

print(l)