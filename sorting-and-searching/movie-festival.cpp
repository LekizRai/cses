#include <bits/stdc++.h>
using namespace std;

bool c(pair<int, int> x, pair<int, int> y)
{
    if (x.second < y.second) {
        return true;
    }
    else if (x.second > y.second) {
        return false;
    }
    else {
        if (x.first < y.first) return true;
        return false;
    }
    return true;
}

int main()
{
    int n, a, b;
    vector<pair<int, int>> t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        t.push_back(pair<int, int> {a, b});
    }
    sort(t.begin(), t.end(), c);
    int cur_t = -1;
    int res = 0;
    for (auto &it: t) {
        if (it.first >= cur_t) {
            res += 1;
            cur_t = it.second;
        }
    }
    cout << res;
    return 0;
}
