#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, cur;
    cin >> n;
    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i+1;
    }
    sort(x.begin(), x.end());
    vector<int> res(n);
    set<int> pos;
    vector<int> tmp;
    pos.insert(0);
    cur = -1;
    for (int i = 0; i < n; i++) {
        if (x[i].first != cur) {
            for (auto &it: tmp) {
                pos.insert(it);
            }
            tmp.clear();
            cur = x[i].first;
        }
        tmp.push_back(x[i].second);
        res[x[i].second-1] = *prev(pos.lower_bound(x[i].second));
    }
    for (auto &it: res) {
        cout << it << " ";
    }
    return 0;
}
