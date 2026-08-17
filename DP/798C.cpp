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

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

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

    // check
    int ggg = gcd(max(a[0], a[1]), min(a[0], a[1]));
    for (int i = 2; i < n; i++)
        ggg = gcd(max(ggg, a[i]), min(ggg, a[i]));
    
    if (ggg > 1) {
        cout << "YES\n0";
        return 0;
    }

    int result = 0;
    int curr_block = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            curr_block++;
        }
        else {
            if (curr_block > 0) {
                result += curr_block / 2;
                if (curr_block % 2 == 1)
                    result += 2;
                curr_block = 0;
            }
        }
    }
    if (curr_block > 0) {
        if (curr_block > 0) {
            result += curr_block / 2;
            if (curr_block % 2 == 1)
                result += 2;
            curr_block = 0;
        }
    }

    cout << "YES\n" << result;
}