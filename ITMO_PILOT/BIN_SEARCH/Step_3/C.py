n, k = map(int, input().split(" "))
coords = list(map(int, input().split(" ")))

def place(minlen: int):
    last = coords[0]
    count = 1

    for i in range(1, n):
        if coords[i] - last >= minlen:
            count += 1
            last = coords[i]

    return count >= k

l = 0
r = int(1e10)
while r - l > 1:
    c = (l + r) // 2

    if place(c):
        l = c
    else:
        r = c

print(l)