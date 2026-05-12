s = list(map(int, input().split(" ")))
t = list(map(int, input().split(" ")))

def pop(arr: list):
    while len(arr) > 0 and arr[-1] == 0:
        arr.pop()

pop(s)
pop(t)

if len(s) == 0:
    print("YES")
    exit(0)

if len(t) == 0 or len(s) < len(t):
    print("NO")
    exit(0)

for i in range(len(s) - 1, len(t) - 2, -1):
    if s[i] % t[-1] != 0:
        print("NO")
        exit(0)
    
    mult = s[i] // t[-1]
    for j in range(len(t)):
        s[i - j] -= t[-(j + 1)] * mult
    

pop(s)
if len(s) > 0:
    print("NO")
    exit(0)

print("YES")