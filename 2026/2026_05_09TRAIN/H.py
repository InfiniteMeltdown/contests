s = [c for c in input()]

if len(s) == 1 or len(s) == 2:
    print("NO SOLIUTON")
    exit(0)

for i in range(1, len(s) - 1):
    if s[i] != s[1]:
        temp = s[i]
        s[i] = s[1]
        s[1] = temp
        print("".join(s))
        exit()

print("NO SOLIUTON")