r, b = map(int, input().split(" "))

if r == b:
    print(r + b)
if r > b:
    print(2 * b + 1)
if r < b:
    print(2 * r + 1)