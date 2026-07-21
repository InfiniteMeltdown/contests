n, k = map(int, input().split(" "))

a = list(map(int, input().split(" ")))

def acquire_sum(s):
    current = 0
    count = 1
    for i in range(n):
        if current + a[i] <= s:
            current += a[i]
        else:
            count += 1
            current = a[i]

    return count <= k

l = max(a) - 1
r = sum(a) + 1
while r - l > 1:
    c = (l + r) // 2

    if acquire_sum(c):
        r = c
    else:
        l = c

print(r)