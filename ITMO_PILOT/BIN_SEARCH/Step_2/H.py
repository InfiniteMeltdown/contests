recipe = input()
req_b = recipe.count("B")
req_s = recipe.count("S")
req_c = recipe.count("C")

nb, ns, nc = map(int, input().split(" "))
pb, ps, pc = map(int, input().split(" "))

rubles = int(input())

def can_make(x):
    buy_b = max(0, req_b * x - nb)
    buy_s = max(0, req_s * x - ns)
    buy_c = max(0, req_c * x - nc)

    return buy_b * pb + buy_s * ps + buy_c * pc <= rubles

l = 0
r = 100000000000000

while r - l > 1:
    c = (l + r) // 2

    if can_make(c):
        l = c
    else:
        r = c

print(l)