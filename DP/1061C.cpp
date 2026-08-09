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

ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<int> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> dp (n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<int> divs;
        for (int j = 1; j * j <= a[i] && j < n + 1; j++) {
            if (a[i] % j == 0) {
                divs.push_back(j);
                if (a[i] / j < n + 1 && j != a[i] / j)
                    divs.push_back(a[i] / j);
            }
        }
        sort(divs.begin(), divs.end());

        for (auto it = divs.rbegin(); it != divs.rend(); it++) {
            int d = *it;
            dp[d] = (dp[d] + dp[d - 1]) % mod;
        }
    }

    ll result = 0;
    for (int i = 1; i < n + 1; i++)
        result = (result + dp[i]) % mod;

    cout << result;
}