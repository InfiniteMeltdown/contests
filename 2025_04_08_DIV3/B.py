t = int(input())

for _ in range(t):
    n = input()
    
    zeros = 0
    best = 1e9
    for i in range(len(n)):
        if n[i] == '0':
            zeros += 1
        else:
            best = min(best, len(n) - 1 - zeros)

    print(best)