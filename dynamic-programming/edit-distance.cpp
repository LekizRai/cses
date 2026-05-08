#include <bits/stdc++.h>
using namespace std;


int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n, m;
    n = int(s1.length());
    m = int(s2.length());
    vector<vector<int>> res(n+1, vector<int> (m+1, 0));
    for (int i = 1; i <= n; i++) {
        res[i][0] = i;
    }
    for (int i = 1; i <= m; i++) {
        res[0][i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i-1] == s2[j-1]) {
                res[i][j] = res[i-1][j-1];
            }
            else {
                res[i][j] = min(res[i-1][j]+1, res[i][j-1]+1);
                res[i][j] = min(res[i][j], res[i-1][j-1]+1);
            }
        }
    }
    cout << res[n][m];
    return 0;
}