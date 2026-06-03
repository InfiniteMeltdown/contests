n = int(input())
a = sorted(list(map(int, input().split(" "))))

def find_mingte(x):
    l = 0
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2

        if a[c] < x:
            l = c
        else:
            r = c

    if a[l] >= x:
        return 0
    return r

def find_maxlte(x):
    l = 0
    r = len(a)
    while r - l > 1:
        c = (l + r) // 2

        if a[c] <= x:
            l = c
        else:
            r = c

    if a[l] > x:
        return -1
    return l

k = int(input())
for i in range(k):
    l, r = map(int, input().split(" "))

    lbound = find_mingte(l)
    rbound = find_maxlte(r)

    print(rbound - lbound + 1)