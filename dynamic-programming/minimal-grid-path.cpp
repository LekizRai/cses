#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    vector<vector<string>> res(2, vector<string> (n));
    for (int i = 0; i < min(n, 1500); i++) {
        cin >> s;
        for (int j = 0; j < min(n, 1500); j++) {
            if (i == 0 && j == 0) {
                res[i][j] = s[j];
            }
            else {
                res[i%2][j] = "a";
                if (i-1 >= 0) {
                    res[i%2][j] = min(res[i%2][j], res[(i+1)%2][j]);
                }
                if (j-1 >= 0) {
                    res[i%2][j] = min(res[i%2][j], res[i%2][j-1]);
                }
                res[i%2][j] += s[j];
            }
        }
    }
    cout << res[(n-1)%2][n-1];
    return 0;
}
