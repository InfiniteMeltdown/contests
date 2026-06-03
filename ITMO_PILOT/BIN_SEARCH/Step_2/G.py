import copy

k = int(input())
n = int(input())

a = []
for i in range(n):
    a.append(int(input()))

a = sorted(a, reverse=True)

def check(groups):
    boiler = [0] * k
    copya = copy.copy(a)

    i = 0
    j = 0
    while i < k and j < n:
        while j < n and boiler[i] < groups:
            delta = min(groups - boiler[i], copya[j])
            boiler[i] += delta
            copya[j] -= delta
            if boiler[i] == groups:
                break
            if copya[j] == 0:
                j += 1
        if boiler[i] == groups:
            i += 1
        if i == k:
            break
        if j == n:
            break

        if copya[j] > 0:
            # fill up to restriction
            boiler[i] = min(copya[j], groups - delta)
            copya[j] -= boiler[i]
        j += 1

    return i == k

l = 1
r = 1000000000000
while r - l > 1:
    c = (l + r) // 2

    if check(c):
        l = c
    else:
        r = c

print(l)