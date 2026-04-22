#include <bits/stdc++.h>
using namespace std;

#define MOD int(1e9+7)


int main() {
    int t, n;
    vector<vector<int>> res(1000001, vector<int> (2, 0));
    res[1][0] = 1;
    res[1][1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        res[i][0] = (res[i][0]+res[i-1][1])%MOD;
        res[i][0] = (res[i][0]+res[i-1][0])%MOD;
        res[i][0] = (res[i][0]+res[i-1][0])%MOD;

        res[i][1] = (res[i][1]+res[i-1][0])%MOD;
        res[i][1] = (res[i][1]+res[i-1][1])%MOD;
        res[i][1] = (res[i][1]+res[i-1][1])%MOD;
        res[i][1] = (res[i][1]+res[i-1][1])%MOD;
        res[i][1] = (res[i][1]+res[i-1][1])%MOD;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (res[n][0]+res[n][1])%MOD << endl;
    }
    return 0;
}