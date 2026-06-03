t = int(input())

def check(a: list):
    seen = set([a[0]])
    for i in range(1, len(a)):
        if a[i - 1] != a[i]:
            if a[i] in seen:
                return False
            
            seen.add(a[i])

    return True


def solve():
    n = int(input())

    a = list(map(int, input().split(" ")))

    if check(a):
        print("YES")
        return

    compressed = [a[0]]
    counts = [1]
    index_start = [0]
    seg_count = {a[0]: 1}
    for i in range(1, n):
        if a[i - 1] != a[i]:
            compressed.append(a[i])
            counts.append(1)
            index_start.append(i)

            if a[i] not in seg_count:
                seg_count[a[i]] = 1
            else:
                seg_count[a[i]] += 1
        else:
            counts[-1] += 1

    k = 0
    for key in seg_count.keys():
        k += seg_count[key]
    if k > len(seg_count) + 4:
        print("NO")
        return
    
    forswap = set()
    for i in range(len(compressed)):
        if seg_count[compressed[i]] == 1:
            continue

        l = index_start[i] - 1
        r = l + 1 + counts[i]
        if l >= 0:
            forswap.add(l)
        if r < n:
            forswap.add(r)
        forswap.add(l + 1)
        forswap.add(r - 1)
    forswap = list(forswap)

    for i in range(len(forswap) - 1):
        for j in range(i + 1, len(forswap)):
            first = forswap[i]
            second = forswap[j]

            temp = a[first]
            a[first] = a[second]
            a[second] = temp

            if check(a):
                print("YES")
                return
            
            temp = a[first]
            a[first] = a[second]
            a[second] = temp
    print("NO")
    return

for _ in range(t):
    solve()