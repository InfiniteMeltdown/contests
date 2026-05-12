n, l, r = map(int, input().split(" "))

bn = bin(n)[2:][::-1]
for i in range(l, min(len(bn), r + 1)):
    if bn[i] != '0':
        print("NO")
        exit(0)

print("YES")