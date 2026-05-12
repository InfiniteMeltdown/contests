import math

def slice(dist, radius):
    gamma = 2 * math.acos(dist / radius)
    return 1 / 2 * gamma * radius * radius - dist * math.sqrt(radius * radius - dist * dist)

def solve(a, b, r):
    total = math.pi * r * r / 2

    if r > a / 2:
        total -= slice(a / 2, r)

    if r > b:
        total -= slice(b, r)

    if r > a / 2 and r > b:
        # check if they intersect
        if math.sqrt(r * r - b * b) >= a / 2:
            total = a * b

    return total

a, b, r = map(int, input().split(" "))
print(max(solve(a, b, r), solve(b, a, r)))