n, d = map(int, input().split(" "))
a = list(map(int, input().split(" ")))

def solve(x):
    b = [item - x for item in a]
    pref = [0] * (n + 1)
    minp = [0] * (n + 1)

    for i in range(n):
        pref[i + 1] = pref[i] + b[i]
        minp[i + 1] = min(minp[i], pref[i + 1])

    for i in range(d - 1, n):
        if pref[i + 1] - minp[i - (d - 1)] >= 0:
            return True

    return False

l = 0
r = sum(a) + 1
for i in range(100):
    c = (l + r) / 2

    if solve(c):
        l = c
    else:
        r = c

b = [item - l for item in a]
pref = [0] * (n + 1)
minp = [0] * (n + 1)
iminp = [0] * (n + 1)

for i in range(n):
    pref[i + 1] = pref[i] + b[i]
    minp[i + 1] = minp[i]
    iminp[i + 1] = iminp[i]
    if minp[i + 1] > pref[i + 1]:
        minp[i + 1] = pref[i + 1]
        iminp[i + 1] = i + 1

for i in range(d - 1, n):
    if pref[i + 1] - minp[i - (d - 1)] >= 0:
        print(iminp[i - (d - 1)] + 1, i + 1)
        exit(0)