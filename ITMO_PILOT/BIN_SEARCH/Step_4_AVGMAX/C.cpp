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

bool comp(pair<double, double>& p1, pair<double, double>& p2) {
    return p1.first > p2.first;
}

bool solve(vector<pair<double, double>> data, int n, int k, double x) {
    for (int i = 0; i < n; i++)
        data[i].first -= data[i].second * x;

    sort(data.begin(), data.end(), comp);

    double result = 0;
    for (int i = 0; i < k; i++)
        result += data[i].first;

    return result >= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, k;
    cin >> n >> k;

    vector<pair<double, double>> data (n);
    for (int i = 0; i < n; i++)
        cin >> data[i].first >> data[i].second;

    double l = 0;
    double r = 1e10;
    for (int i = 0; i < 100; i++) {
        double c = (l + r) / 2;

        if (solve(data, n, k, c))
            l = c;
        else
            r = c;
    }

    cout << l;
}