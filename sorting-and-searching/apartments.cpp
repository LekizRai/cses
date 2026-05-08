#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n, 0), b(m, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int id_a = 0;
    int id_b = 0;
    int res = 0;
    while (id_a < n && id_b < m) {
        if (abs(a[id_a]-b[id_b]) <= k) {
            res += 1;
            id_a += 1;
            id_b += 1;
        }
        else {
            if (a[id_a] < b[id_b]) {
                id_a += 1;
            }
            else if (a[id_a] > b[id_b]) {
                id_b += 1;
            }
        }
    }
    cout << res;
    return 0;
}
