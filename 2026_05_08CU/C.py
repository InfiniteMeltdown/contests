n = input()

rev = n[::-1]

if int(n) % int(rev) == 0:
    print("YES")
    exit(0)

print("NO")