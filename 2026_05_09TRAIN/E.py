a, b = map(int, input().split(" "))

if a == 1 and b == 1:
    print(1.0)
    exit(0)

dp = [[0] * (b + 1) for _ in range(a + 1)]
dp[1][1] = a * b * (a + b - 2) / 2
for i in range(1, a):
    dp[i + 1][1] = dp[i][1] + b * (2 * i - a)

for i in range(1, a + 1):
    for j in range(1, b):
        dp[i][j + 1] = dp[i][j] + a * (2 * j - b)

result = 0
for i in range(1, a + 1):
    result += sum(dp[i])

print(result / (a * b * (a * b - 1)))