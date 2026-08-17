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

bool sort_inv(char a, char b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    string a, b;
    cin >> a >> b;

    if (a.size() < b.size()) {
        sort(a.begin(), a.end(), sort_inv);
        cout << a;
        return 0;
    }

    map<int, int> digs;
    for (int i = 0; i < a.size(); i++)
        digs[a[i] - '0']++;

    bool lower = false;
    vector<int> answer (a.size(), 0);
    int i = 0;
    while (i < a.size() && !lower) {
        auto it = digs.lower_bound(b[i] - '0');
        if (it == digs.end() || it->first > b[i] - '0' && it != digs.begin())
            it--;

        if (it->first > b[i] - '0') {
            for (int j = i - 1; j >= 0; j--) {
                i = j + 1;
                digs[answer[j]]++;

                auto prev_jit = digs.lower_bound(b[j] - '0');
                if (prev_jit->first > b[j] - '0' && prev_jit != digs.begin())
                    prev_jit--;

                auto jit = digs.lower_bound(prev_jit->first);
                if (jit != digs.begin())
                    jit--;

                if (jit->first == prev_jit->first)
                    continue;

                lower = true;
                answer[j] = jit->first;
                jit->second--;
                if (jit->second == 0)
                    digs.erase(jit);
                break;
            }
            
            break;
        }

        if (it->first < b[i] - '0')
            lower = true;

        answer[i++] = it->first;
        it->second--;
        if (it->second == 0)
            digs.erase(it);
    }

    for (; i < a.size(); i++) {
        auto it = digs.rbegin();
        answer[i] = it->first;
        it->second--;
        if (it->second == 0)
            digs.erase(--(it.base()));
    }

    for (int d : answer)
        cout << d;
}