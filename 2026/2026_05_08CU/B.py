data = list(map(int, input().split(" ")))

l = 0
r = 0
curr = 0
while curr < 1000:
    curr += data[r]
    r += 1

bestl = 0
bestr = r
best = curr
while r < len(data):
    curr -= data[l]
    l += 1
    while curr < 1000 and r < len(data):
        curr += data[r]
        r += 1
    
    if curr >= 1000:
        if r - l < bestr - bestl or (r - l == bestr - bestl and curr > best):
            bestl = l
            bestr = r
            best = curr

print(bestl + 1)