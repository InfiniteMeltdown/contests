n, k = map(int, input().split(" "))

a = sorted(list(map(int, input().split(" "))))
b = sorted(list(map(int, input().split(" "))))

def count(x):
    result = 0
    for i in range(n):
        l = 0
        r = n
        while r - l > 1:
            c = (l + r) // 2

            if b[i] + a[c] < x:
                l = c
            else:
                r = c

        if b[i] + a[l] < x:
            result += l + 1

    return result

l = 0
r = int(1e10)
while r - l > 1:
    c = (l + r) // 2

    if count(c) <= (k - 1):
        l = c
    else:
        r = c

print(l)