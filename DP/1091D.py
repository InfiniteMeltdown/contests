n = int(input())
mod = 998244353

fact = [1, 1, 2]
def get_fact(x):
    while x >= len(fact):
        fact.append((fact[-1] * len(fact)) % mod)

    return fact[x]

def fast_pow(num, pow):
    if pow == 0:
        return 1

    if pow % 2 == 0:
        result = fast_pow(num, pow / 2)
        return (result * result) % mod
    return (num * fast_pow(num, pow - 1)) % mod

def inv_mod(num):
    return fast_pow(num, mod - 2)

result = (n * get_fact(n)) % mod

for i in range(1, n):
    result = (result - (get_fact(n) * inv_mod(get_fact(i))) % mod) % mod
    if result < 0:
        result += mod

print(result)