#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<int>> res(x+1, vector<int> (2, 0));
    res[0][0] = 0;
    res[0][1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 1; j--) {
            res[j][0] = max(res[j][0], res[j][1]);
            if (j >= h[i]) {
                res[j][1] = max(res[j-h[i]][0]+s[i],res[j-h[i]][1]+s[i]);
            }
            else {
                res[j][1] = 0;
            }
        }
    }
    cout << max(res[x][0], res[x][1]);
    return 0;
}