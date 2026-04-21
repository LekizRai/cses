#include <bits/stdc++.h>
using namespace std;

#define MOD int(1e9+7)


int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<int> res(x+1, 0);
    sort(c.begin(), c.end());
    res[0] = 1;
    for (auto &it: c) {
        for (int i = 1; i <= x; i++) {
            if (i >= it) res[i] = (res[i]+res[i-it])%MOD;
        }
    }
    cout << res[x];
    return 0;
}
