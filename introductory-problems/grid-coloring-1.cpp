#include <bits/stdc++.h>
using namespace std;

string s[500];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    bool free[4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                free[k] = true;
            }
            free[s[i][j]-'A'] = false;
            if (i-1 >= 0) {
                free[s[i-1][j]-'A'] = false;
            }
            if (j-1 >= 0) {
                free[s[i][j-1]-'A'] = false;
            }
            for (int k = 0; k < 4; k++) {
                if (free[k]) {
                    s[i][j] = 'A'+k;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
    return 0;
}
