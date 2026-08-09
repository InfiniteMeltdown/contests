#include <iostream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>

#define ll long long

using namespace std;

ll mod = 998244353;

vector<ll> fact {1, 1, 2};
ll get_fact(ll n) {
    while (n >= fact.size())
        fact.push_back((fact[fact.size() - 1] * fact.size()) % mod);
    return fact[n];
}

ll fast_pow(ll num, ll pow) {
    if (pow == 0)
        return 1;

    if (pow % 2 == 0) {
        ll result = fast_pow(num, pow / 2);
        return (result * result) % mod;
    }
    return (num * fast_pow(num, pow - 1)) % mod;
}

ll inv_mod(ll num) {
    return fast_pow(num, mod - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    ll n;
    cin >> n;

    ll result = (n * get_fact(n)) % mod;

    for (int i = 1; i < n; i++) {
        result = (result - (get_fact(n) * inv_mod(get_fact(i))) % mod) % mod;
        if (result < 0)
            result += mod;
    }

    cout << result;
}