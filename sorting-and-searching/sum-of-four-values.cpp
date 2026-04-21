#include <bits/stdc++.h>
using namespace std;

#define lli long long int


pair<int, int> find_val(vector<pair<lli, int>> &a, int val, int lb, int ub)
{
    pair<int, int> res;
    res.first = -1;
    while (lb < ub) {
        if (a[lb].first+a[ub].first > val) {
            ub -= 1;
        }
        else if (a[lb].first+a[ub].first < val) {
            lb += 1;
        }
        else {
            res.first = lb;
            res.second = ub;
            return res;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, x;
    cin >> n >> x;
    vector<pair<lli, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    pair<int, int> res;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            res = find_val(a, x-a[i].first-a[j].first, j+1, n-1);
            if (res.first >= 0) {
                cout << a[i].second+1 << " " << a[j].second+1 << " " << a[res.first].second+1 << " " << a[res.second].second+1;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
