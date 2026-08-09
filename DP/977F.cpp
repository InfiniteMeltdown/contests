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

class Entry {
public:
    int id, num, len;

    bool operator()(const Entry& e1, const Entry& e2) const {
        if (e1.num != e2.num)
            return e1.num < e2.num;
        return e1.len < e2.len;
    }
};

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

    multiset<Entry, Entry> prev {{0, a[0], 1}};
    vector<int> history (n, -1);
    for (int i = 1; i < n; i++) {
        int current = a[i];

        auto it = prev.lower_bound({-1, current - 1, INT_MAX});
        if (it != prev.begin())
            it--;

        if (it->num >= current || it->num + 1 < current) {
            prev.insert({i, current, 1});
            continue;
        }

        prev.insert({i, current, it->len + 1});
        history[i] = it->num;
    }

    Entry best = *(prev.begin());
    for (auto it = prev.begin(); it != prev.end(); it++){
        if (best.len < it->len)
            best = *it;
    }

    vector<int> result;
    cout << best.len << "\n";
    Entry currEntry = best;
    while (history[currEntry.id] != -1) {
        result.push_back(currEntry.id);
        currEntry = *prev.find({-1, history[currEntry.id], currEntry.len - 1});
    }
    cout << currEntry.id + 1 << " ";
    for (auto it = result.rbegin(); it != result.rend(); it++)
        cout << (*it) + 1 << " ";
}