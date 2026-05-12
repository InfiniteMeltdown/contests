source = input()
compressed = []

count = 1
for i in range(1, len(source)):
    if source[i] == source[i - 1]:
        count += 1
    else:
        compressed.append(count)
        count = 1
compressed.append(count)

if source[0] == source[-1]:
    compressed[0] += compressed[-1]
    compressed.pop()

totalsum = sum(compressed)

def solve(compressed):
    i = 2
    leftsum = compressed[0]
    rightsum = totalsum - compressed[0]
    bestdelta = abs(rightsum - leftsum)
    while i < len(compressed) and abs(leftsum + compressed[i] + compressed[i - 1] - (rightsum - compressed[i] - compressed[i - 1])) < abs(leftsum - rightsum):
        leftsum += compressed[i] + compressed[i - 1]
        rightsum -= compressed[i] + compressed[i - 1]
        i += 2
        bestdelta = min(bestdelta, abs(leftsum - rightsum))

    for j in range(1, len(compressed), 2):
        leftsum -= compressed[j - 1] + compressed[j]
        rightsum += compressed[j - 1] + compressed[j]
        
        inner_i = i % len(compressed)
        previnner_i = inner_i - 1
        if previnner_i < 0:
            previnner_i += len(compressed)
        while abs(leftsum + compressed[inner_i] + compressed[previnner_i] - (rightsum - compressed[inner_i] - compressed[previnner_i])) < abs(leftsum - rightsum):
            leftsum += compressed[inner_i] + compressed[previnner_i]
            rightsum -= compressed[inner_i] + compressed[previnner_i]
            i += 2
            bestdelta = min(bestdelta, abs(leftsum - rightsum))
            inner_i = i % len(compressed)
            previnner_i = inner_i - 1
            if previnner_i < 0:
                previnner_i += len(compressed)

    return bestdelta

bestdelta = solve(compressed)

temp = compressed[0]
del compressed[0]
compressed.append(temp)
bestdelta = min(bestdelta, solve(compressed))

print(bestdelta)