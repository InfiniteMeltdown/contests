n, x, y = map(int, input().split(" "))

result = min(x, y)
n -= 1

def can_print(t):
    return (t // x) + (t // y) >= n

l = 0
r = n * x + n * y
while r - l > 1:
    c = (l + r) // 2

    if not can_print(c):
        l = c
    else:
        r = c

print(result + r)