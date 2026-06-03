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

struct FenTree {
    int size;
    vector<ll> a;

    FenTree(int source) {
        size = source;
        a.assign(size, 0);
    }

    void inc(int i, ll delta) {
        for (; i < size; i = i | (i + 1))
            a[i] += delta;
    }

    ll sum(int i) {
        ll result = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            result += a[i];

        return result;
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

    vector<int> st;
    vector<int> prevGreater (n, -1);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.back()] < a[i]){
            prevGreater[st.back()] = i;
            st.pop_back();
        }

        st.push_back(i);
    }

    st.clear();
    vector<int> nextLess (n, n + 1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.back()] > a[i]) {
            nextLess[st.back()] = i;
            st.pop_back();
        }

        st.push_back(i);
    }

    st.clear();
    

    FenTree ftPrevGreater (n);
    for (int i = 0; i < n; i++) {
        if ()
    }
}