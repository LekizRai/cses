#include <bits/stdc++.h>
using namespace std;

#define lli long long int


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, x, res;
    cin >> n >> x;
    vector<lli> a(n);
    vector<lli> cumul(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) cumul[i] = a[i];
        else cumul[i] = cumul[i-1]+a[i];
    }
    map<lli, vector<int>> cumul2id;
    for (int i = 0; i < n; i++) {
        if (cumul2id.count(cumul[i]) > 0) {
            cumul2id[cumul[i]].push_back(i);
        }
        else {
            cumul2id[cumul[i]] = vector<int> {i};
        }
    }
    res = 0;
    if (cumul2id.count(x) > 0) {
        res += int(cumul2id[x].size());
    }
    for (int i = 0; i < n; i++) {
        if (cumul2id.count(cumul[i]+x) > 0) {
            res += cumul2id[cumul[i]+x].end()-lower_bound(cumul2id[cumul[i]+x].begin(), cumul2id[cumul[i]+x].end(), i+1);
        }
    }
    cout << res;
    return 0;
}

