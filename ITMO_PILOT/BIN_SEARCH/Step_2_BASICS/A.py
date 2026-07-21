import math

w, h, n = map(int, input().split(" "))

def can_pack(x):
    return math.floor(x / w) * math.floor(x / h) >= n

l = 0
r = 1
while not can_pack(r):
    r <<= 1

while r - l > 1:
    c = (l + r) // 2

    if not can_pack(c):
        l = c
    else:
        r = c

print(r)