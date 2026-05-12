s = input().split(" ")

answer = []
for entry in s:
    poly = True
    for i in range(len(entry) // 2):
        if entry[i] != entry[len(entry) - 1 - i]:
            poly = False
            break

    if poly:
        answer.append(entry)

print(*answer)