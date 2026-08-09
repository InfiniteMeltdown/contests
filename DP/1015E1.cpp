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

struct Entry {
    int i, j, size;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << fixed << setprecision(9);

    int n, m;
    cin >> n >> m;

    vector<string> field (n);
    for (int i = 0; i < n; i++)
        cin >> field[i];
    vector<vector<bool>> filled (n, vector<bool> (m, false));

    vector<Entry> stars;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] != '*')
                continue;
            
            int size = 0;
            for (int k = 1; k < 100; k++) {
                if (i - k < 0 || j + k >= m || i + k >= n || j - k < 0)
                    break;

                if (field[i - k][j] != '*' || field[i][j + k] != '*' || field[i + k][j] != '*' || field[i][j - k] != '*')
                    break;
                
                size = k;
            }
            
            if (size > 0){
                stars.push_back({i, j, size});
                for (int k = 0; k <= size; k++) {
                    filled[i - k][j] = true;
                    filled[i][j + k] = true;
                    filled[i + k][j] = true;
                    filled[i][j - k] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (field[i][j] == '*' && !filled[i][j]) {
                cout << -1;
                return 0;
            }

    cout << stars.size() << "\n";
    for (int i = 0; i < stars.size(); i++)
        cout << stars[i].i + 1 << " " << stars[i].j + 1 << " " << stars[i].size << "\n";
}