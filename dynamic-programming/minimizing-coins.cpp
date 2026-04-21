#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<int> res(x+1, 1e9);
    res[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (auto &it: c) {
            if (it <= i) res[i] = min(res[i-it]+1, res[i]);
        }
    }
    if (res[x] == 1e9) cout << -1;
    else cout << res[x];
    return 0;
}
