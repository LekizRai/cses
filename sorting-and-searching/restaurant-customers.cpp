#include <bits/stdc++.h>
using namespace std;


int st[400000], fi[400000];

int main()
{
    int n, a, b;
    cin >> n;
    set<int> tmp;
    vector<pair<int, int>> t;
    pair<int, int> ab;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        t.push_back({a, b});
        tmp.insert(a);
        tmp.insert(b);
    }
    int len = tmp.size();
    int id = 0;
    map<int, int> time;
    for (auto &it: tmp) {
        time[it] = id;
        id++;
    }
    for (int i = 0; i < len; i++) {
        st[i] = 0;
        fi[i] = 0;
    }
    for (auto &it: t) {
        st[time[it.first]] += 1;
        fi[time[it.second]] += 1;
    }
    int max_num = -1;
    int cur_num = 0;
    for (int i = 0; i < len; i++) {
        cur_num += st[i] - fi[i];
        max_num = max(max_num, cur_num);
    }
    cout << max_num;
    return 0;
}
