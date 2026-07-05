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

bool solve(int n, int d, int maxlen, vector<vector<int>> &links, vector<vector<int>> &weights) {
    vector<int> dp (n, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        if (dp[i] != INT_MAX) {
            for (int j = 0; j < links[i].size(); j++) {
                if (weights[i][j] > maxlen)
                    continue;
                
                dp[links[i][j]] = min(dp[links[i][j]], dp[i] + 1);
            }
        }
    }

    return dp[n - 1] <= d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, m, d;
    cin >> n >> m >> d;

    vector<vector<int>> links (n);
    vector<vector<int>> weights (n);
    set<int> all_weights;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        links[a - 1].push_back(b - 1);
        weights[a - 1].push_back(c);
        all_weights.insert(c);
    }

    vector<int> possible_weights (all_weights.begin(), all_weights.end());
    int l = -1;
    int r = possible_weights.size() - 1;

    while (r - l > 1) {
        int c = (l + r) / 2;

        if (solve(n, d, possible_weights[c], links, weights))
            r = c;
        else
            l = c;
    }

    int maxlen = possible_weights[r];
    vector<int> dp (n, INT_MAX); dp[0] = 0;
    vector<int> trace (n, -1);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        if (dp[i] != INT_MAX) {
            for (int j = 0; j < links[i].size(); j++) {
                if (weights[i][j] > maxlen)
                    continue;
                
                if (dp[links[i][j]] > dp[i] + 1) {
                    dp[links[i][j]] = min(dp[links[i][j]], dp[i] + 1);
                    trace[links[i][j]] = i;
                }
            }
        }
    }
    
    if (dp[n - 1] > d) {
        cout << -1;
        return 0;
    }

    vector<int> path (dp[n - 1] + 1); path[dp[n - 1]] = n - 1;
    for (int i = dp[n - 1] - 1; i >= 0; i--)
        path[i] = trace[path[i + 1]];

    cout << path.size() - 1 << "\n";
    for (int i : path)
        cout << i + 1 << " ";
}