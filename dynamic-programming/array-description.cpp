#include <bits/stdc++.h>
using namespace std;

#define MOD int(1e9+7)


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<vector<int>> res(2, vector<int> (m+1, 0));
    int cur_id = 0;
    if (x[0] != 0) {
        for (int i = 1; i <= m; i++) {
            if (i == x[0]) {
                res[0][i] = 1;
                res[1][i] = 1;
            }
        }
    }
    else {
        for (int i = 1; i <= m; i++) {
            res[0][i] = 1;
            res[1][i] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) res[cur_id][j] = 0;
        for (int j = 1; j <= m; j++) {
            if (x[i] != 0 && x[i] != j) continue; 
            if (j == 1) {
                res[cur_id][j] = (res[cur_id][j]+res[1-cur_id][j])%MOD;
                res[cur_id][j] = (res[cur_id][j]+res[1-cur_id][j+1])%MOD;
            }
            else if (j == m) {
                res[cur_id][j] = (res[cur_id][j]+res[1-cur_id][j-1])%MOD;
                res[cur_id][j] = (res[cur_id][j]+res[1-cur_id][j])%MOD;
            }
            else {
                res[cur_id][j] = (res[cur_id][j]+res[1-cur_id][j-1])%MOD;
                res[cur_id][j] = (res[cur_id][j]+res[1-cur_id][j])%MOD;
                res[cur_id][j] = (res[cur_id][j]+res[1-cur_id][j+1])%MOD;
            }
        }
        cur_id = 1-cur_id;
    }
    int sum_res = 0;
    for (int i = 1; i <= m; i++) sum_res = (sum_res+res[1-cur_id][i])%MOD;
    cout << sum_res;
    return 0;
}
