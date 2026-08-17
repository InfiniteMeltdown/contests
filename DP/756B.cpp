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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n;
    cin >> n;

    vector<int> t (n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    vector<int> dp (n + 1, 0);
    multiset<int> off90 {0};
    multiset<int> off1440 {0};
    int j90 = 0;
    int j1440 = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] + 20;

        while (t[i] - t[j90] + 1 > 90)
            off90.erase(off90.find(dp[j90++]));
        while (t[i] - t[j1440] + 1 > 1440)
            off1440.erase(off1440.find(dp[j1440++]));

        dp[i + 1] = min(dp[i + 1], (*off90.begin()) + 50);
        dp[i + 1] = min(dp[i + 1], (*off1440.begin()) + 120);

        off90.insert(dp[i + 1]);
        off1440.insert(dp[i + 1]);

        cout << dp[i + 1] - dp[i] << "\n";
    }
}