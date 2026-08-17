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

bool dfs(int curr, int prev, vector<vector<int>>& links, vector<int>& color, vector<int>& topsort) {
    color[curr] = 1;

    for (int next : links[curr]) {
        if (color[next] == 1)
            return false;

        if (color[next] == 2)
            continue;

        bool result = dfs(next, curr, links, color, topsort);
        if (!result)
            return false;
    }

    color[curr] = 2;
    topsort.push_back(curr);
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> links (n);
    vector<int> value (n);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        value[i] = c - 'a';
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        links[u - 1].push_back(v - 1);
    }

    vector<int> topsort;
    vector<int> color (n, 0);
    for (int i = 0; i < n; i++) {
        if (color[i] != 0)
            continue;

        bool result = dfs(i, -1, links, color, topsort);
        if (!result) {
            cout << -1;
            return 0;
        }
    }

    int best = INT_MIN;
    for (int i = 0; i <= 'z' - 'a'; i++) {
        vector<int> dp (n, 0);
        int currbest = INT_MIN;

        for (int j = 0; j < n; j++) {
            int curr = topsort[j];

            for (int next : links[curr])
                dp[curr] = max(dp[curr], dp[next]);

            if (value[curr] == i)
                dp[curr]++;

            currbest = max(currbest, dp[curr]);
        }

        best = max(best, currbest);
    }

    cout << best;
}