#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 10000;
        }
    }
    a[0][0] = 0; a[0][1] = 3; a[0][2] = 2; a[0][3] = 3;
    a[1][0] = 3; a[1][1] = 4; a[1][2] = 1; a[1][3] = 2;
    a[2][0] = 2; a[2][1] = 1; a[2][2] = 4; a[2][3] = 3;
    a[3][0] = 3; a[3][1] = 2; a[3][2] = 3; a[3][3] = 2;
    if (n == 4) {
        a[3][0] = 5;
        a[0][3] = 5;
    }
    else {
        for (int m = 5; m <= n; m++) {
            for (int i = 0; i < m-1; i++) {
                if (i-2 >= 0 && m-2 >= 0) {
                    a[i][m-1] = min(a[i][m-1], a[i-2][m-2]+1);
                    a[m-1][i] = a[i][m-1];
                }
                if (i+2 < m-1 && m-2 >= 0) {
                    a[i][m-1] = min(a[i][m-1], a[i+2][m-2]+1);
                    a[m-1][i] = a[i][m-1];
                }
                if (i-1 >= 0 && m-3 >= 0) {
                    a[i][m-1] = min(a[i][m-1], a[i-1][m-3]+1);
                    a[m-1][i] = a[i][m-1];
                }
                if (i+1 < m-1 && m-3 >= 0) {
                    a[i][m-1] = min(a[i][m-1], a[i+1][m-3]+1);
                    a[m-1][i] = a[i][m-1];
                }
            }
            a[m-1][m-1] = a[m-3][m-2]+1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
