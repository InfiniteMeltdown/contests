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

    string s;
    cin >> s;

    vector<int> a (26);
    for (int i = 0; i < 26; i++)
        cin >> a[i];

    vector<ll> dp (n + 1, 0);
    dp[0] = 1;
    int longest_segment = INT_MIN;
    for (int i = 0; i < n; i++) {
        set<int> found;
        for (int j = i; j >= 0; j--) {
            found.insert(s[j] - 'a');

            int lowest = INT_MAX;
            for (auto it = found.begin(); it != found.end(); it++)
                lowest = min(lowest, a[*it]);

            if (i - j + 1 > lowest)
                break;

            dp[i + 1] = (dp[i + 1] + dp[j]) % mod;
            longest_segment = max(longest_segment, i - j + 1);
        }
    }

    int min_count = 0;
    set<int> current_seg;
    int start = 0;
    for (int i = 0; i < n; i++) {
        current_seg.insert(s[i] - 'a');

        int lowest = INT_MAX;
        for (auto it = current_seg.begin(); it != current_seg.end(); it++)
            lowest = min(lowest, a[*it]);

        if (i - start + 1 > lowest) {
            min_count++;
            start = i;
            current_seg.clear();
            current_seg.insert(s[i] - 'a');
        }
    }
    min_count++;

    cout << dp[n] << "\n" << longest_segment << "\n" << min_count;
}