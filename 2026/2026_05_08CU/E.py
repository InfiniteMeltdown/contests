n = int(input())

while n < 0:
    n += 86400

h = n // 3600
m = (n - h * 3600) // 60
s = (n - h * 3600 - m * 60)

print("{h:02d}:{m:02d}:{s:02d}".format(h=h, m=m, s=s))