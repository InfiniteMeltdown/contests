m, n = map(int, input().split(" "))
t = []
z = []
y = []

for i in range(n):
    ti, zi, yi = map(int, input().split(" "))
    t.append(ti)
    z.append(zi)
    y.append(yi)

if m == 0:
    print(0)
    print("".join(["0 "] * n))
    exit(0)

def inflate(T):
    per_worker = []
    for i in range(n):
        a_worker = T // (t[i] * z[i] + y[i]) * z[i]

        rest = T % (t[i] * z[i] + y[i])
        a_worker += min(rest // t[i], z[i])

        per_worker.append(a_worker)

    return per_worker

l = 0
# r = max(t) * m + m // min(z) * max(y)
r = 1000000000
while r - l > 1:
    c = (l + r) // 2

    if sum(inflate(c)) < m:
        l = c
    else:
        r = c

counts = inflate(r)
print(r)
if sum(counts) == m:
    print("".join([str(i) + " " for i in counts]))
else:
    answer = []
    left = m
    for i in range(n):
        delta = min(left, counts[i])
        left -= delta
        answer.append(delta)

    print("".join([str(i) + " " for i in answer]))