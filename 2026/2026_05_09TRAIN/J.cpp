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

    map<int, int> tempcols, temprows;
    for (int i = 0; i < n; i++) {
        char type; int ind;
        cin >> type >> ind;

        if (type == 'C')
            tempcols[ind]++;
        else
            temprows[ind]++;
    }
    
    // remove dups
    vector<int> cols, rows;
    for (auto it = tempcols.begin(); it != tempcols.end(); it++)
        if (it->second % 2 == 1)
            cols.push_back(it->first);
    
    for (auto it = temprows.begin(); it != temprows.end(); it++)
        if (it->second % 2 == 1)
            rows.push_back(it->first);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        ll r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        ll a = r2 - r1 + 1;
        ll b = c2 - c1 + 1;

        auto lc = lower_bound(cols.begin(), cols.end(), c1);
        auto hc = upper_bound(cols.begin(), cols.end(), c2);

        auto lr = lower_bound(rows.begin(), rows.end(), r1);
        auto hr = upper_bound(rows.begin(), rows.end(), r2);
        
        ll cins = hc - lc;
        if (cols.size() == 0)
            cins = 0;
        ll rins = hr - lr;
        if (rows.size() == 0)
            rins = 0;

        ll answer = cins * a + rins * b - 2ll * cins * rins;
        cout << answer << "\n";
    }
}