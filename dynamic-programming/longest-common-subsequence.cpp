#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector<vector<int>> res(n+1, vector<int> (m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                res[i][j] = res[i-1][j-1]+1;
            }
            else {
                res[i][j] = max(res[i-1][j], res[i][j-1]);
                res[i][j] = max(res[i][j], res[i-1][j-1]);
            }
        }
    }
    cout << res[n][m] << endl;
    int i, j;
    i = n; j = m;
    vector<int> res_arr;
    while (res[i][j]) {
        if (a[i-1] == b[j-1]) {
            res_arr.push_back(a[i-1]);
            i -= 1;
            j -= 1;
        }
        else {
            while (res[i-1][j] == res[i][j]) i -= 1;
            while (res[i][j-1] == res[i][j]) j -= 1;
        }
    }
    reverse(res_arr.begin(), res_arr.end());
    for (auto &it: res_arr) cout << it << " ";
    return 0;
}
