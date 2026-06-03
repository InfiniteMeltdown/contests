n, k = map(int, input().split(" "))

a = list(map(int, input().split(" ")))
q = list(map(int, input().split(" ")))

for i in range(k):
    query = q[i]

    l = 0
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2

        if a[c] < query:
            l = c
        else:
            r = c

    if a[l] >= query:
        print(1)
        continue
    print(r + 1)