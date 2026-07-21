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

class Node {
public:
    int id;
    double dist;

    bool operator()(const Node& n1, const Node& n2) const {
        if (n1.dist != n2.dist)
            return n1.dist < n2.dist;
        return n1.id < n2.id;
    }
};

bool solve(vector<vector<int>>& links, vector<vector<double>> weights, double x) {
    for (int i = 0; i < weights.size(); i++)
        for (int j = 0; j < weights[i].size(); j++)
            weights[i][j] -= x;
    
    vector<double> dist (links.size(), INT_MAX);
    dist[0] = 0;

    for (int i = 0; i < links.size(); i++) {
        for (int j = 0; j < links[i].size(); j++) {
            int next = links[i][j];
            double w = weights[i][j];

            dist[next] = min(dist[next], dist[i] + w);
        }
    }

    return dist[links.size() - 1] <= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> links (n);
    vector<vector<double>> weights (n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        links[a - 1].push_back(b - 1);
        weights[a - 1].push_back(c);
    }

    double l = -1;
    double r = 1e9;
    for (int i = 0; i < 100; i++) {
        double c = (l + r) / 2;

        if (solve(links, weights, c))
            r = c;
        else
            l = c;
    }

    for (int i = 0; i < weights.size(); i++)
        for (int j = 0; j < weights[i].size(); j++)
            weights[i][j] -= r;

    vector<double> dist (links.size(), INT_MAX);
    dist[0] = 0;

    vector<int> path (links.size(), -1);

    for (int i = 0; i < links.size(); i++) {
        for (int j = 0; j < links[i].size(); j++) {
            int next = links[i][j];
            double w = weights[i][j];
            
            if (dist[next] > dist[i] + w) {
                dist[next] = dist[i] + w;
                path[next] = i;
            }
            
        }
    }

    vector<int> actual_path;
    int curr = n - 1;
    while (curr != -1) {
        actual_path.push_back(curr);
        curr = path[curr];
    }

    cout << actual_path.size() - 1 << "\n";
    for (auto it = actual_path.rbegin(); it != actual_path.rend(); it++)
        cout << (*it) + 1 << " ";
}