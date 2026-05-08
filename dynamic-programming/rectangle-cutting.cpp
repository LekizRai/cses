#include <bits/stdc++.h>
using namespace std;


int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    vector<vector<int>> res(b+1, vector<int> (b+1, 0));
    for (int i = 1; i <= b; i++) {
        res[i][1] = i-1;
        res[1][i] = i-1;
    }
    for (int i = 2; i <= b; i++) {
        for (int j = 2; j <= b; j++) {
            if (i == j) {
                res[i][j] = 0;
                continue;
            }
            res[i][j] = 1e9+7;
            for (int k = 1; k <= j-1; k++) {
                res[i][j] = min(res[i][j], res[i][k]+res[i][j-k]+1);
            }
            for (int k = 1; k <= i-1; k++) {
                res[i][j] = min(res[i][j], res[i-k][j]+res[k][j]+1);
            }
        }
    }
    cout << res[a][b];
    return 0;
}