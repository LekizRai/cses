#include <bits/stdc++.h>
using namespace std;

#define MOD int(1e9+7)


int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    if (s[0][0] == '*') {
        cout << 0;
        return 0;
    }
    else if (s[n-1][n-1] == '*') {
        cout << 0;
        return 0;
    }
    vector<vector<int>> res(n, vector<int> (n, 0));
    res[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '*') continue;
            if (i > 0) res[i][j] = (res[i][j] + res[i-1][j])%MOD;
            if (j > 0) res[i][j] = (res[i][j] + res[i][j-1])%MOD;
        }
    }
    cout << res[n-1][n-1];
    return 0;
}