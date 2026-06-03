t = input()
p = input()

order = list(map(int, input().split(" ")))
removed = [False] * len(order)

def check(c):
    for i in range(c + 1):
        removed[order[i] - 1] = True

    i = 0
    j = 0
    while i < len(t) and j < len(p):
        while i < len(t) and (removed[i] or t[i] != p[j]):
            i += 1

        if i < len(t):
            i += 1
            j += 1

    for i in range(len(removed)):
        removed[i] = False

    return j == len(p)

l = 0
r = len(order)
while r - l > 1:
    c = (l + r) // 2

    if check(c):
        l = c
    else:
        r = c

if check(l):
    print(l + 1)
else:
    print(0)