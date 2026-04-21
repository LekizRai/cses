#include <bits/stdc++.h>
using namespace std;

bool c(pair<int, int> x, pair<int, int> y)
{
    if (x.first < y.first) return true;
    return false;
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), c);
    int i = 0;
    int j = n-1;
    while (i < j) {
        if (a[i].first+a[j].first < x) {
            i += 1;
        }
        else if (a[i].first+a[j].first > x) {
            j -= 1;
        }
        else {
            cout << a[i].second+1 << " " << a[j].second+1;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
