import sys
sys.set_int_max_str_digits(0)

s, c = input().split(" ")
c = int(c)

l = len(s) // 2 - 1
r = len(s)

def func(i):
    a = int(s[:i])
    b = int(s[i:])
    return a - b * c

while r - l > 1:
    i = (l + r) // 2

    result = func(i)
    if result == 0:
        l = i
        break
    if result <= 0:
        l = i
    else:
        r = i

print(s[:l], s[l:])