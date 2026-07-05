n, m = map(int, input().split(" "))

field = []
for i in range(n):
    vals = list(map(int, input().split(" ")))
    field.append(vals)

result = []
for i in range(m - 1):
    result.append(field[0][i])

for i in range(n - 1):
    result.append(field[i][m - 1])

for i in range(m - 1, 0, -1):
    result.append(field[n - 1][i])

for i in range(n - 1, 0, -1):
    result.append(field[i][0])

for j in range(1, m - 1):
    for i in range(1, n - 1):
        if j % 2 == 1:
            result.append(field[i][j])
        else:
            result.append(field[n - 1 - i][j])

print("".join([str(item) + " " for item in result]))