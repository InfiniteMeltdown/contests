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

    int k, n;
    cin >> k >> n;

    map<int, int> groups;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        groups[a] = i;
    }

    int result = 0;
    while (groups.size() >= k) {
        
    }
}