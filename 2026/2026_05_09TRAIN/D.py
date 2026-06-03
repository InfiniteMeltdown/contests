n = int(input())
a = list(map(int, input().split(" ")))

if n == 1:
    print(1)
    exit(0)

memf = [1, 1, 2]
def fact(n):
    while n >= len(memf):
        memf.append(memf[-1] * len(memf))
    return memf[n]

def comb(n, k):
    return fact(n) // fact(k) // fact(n - k)

result = 0
count = 2
asc = a[0] < a[1]
for i in range(2, n):
    if asc and a[i - 1] > a[i] or not asc and a[i - 1] < a[i]:
        result += comb(count, 2)
        count = 2
        asc = a[i - 1] < a[i]
    else:
        count += 1

result += comb(count, 2)

print(result + n)