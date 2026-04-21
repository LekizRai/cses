#include <bits/stdc++.h>
using namespace std;

int a[100][100];
bool exist[200];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 2*n; i++) {
        exist[i] = false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < 2*n; i++) {
                exist[i] = false;
            }
            for (int k = 0; k < i; k++) {
                exist[a[k][j]] = true;
            }
            for (int k = 0; k < j; k++) {
                exist[a[i][k]] = true;
            }
            for (int k = 0; true; k++) {
                if (!exist[k]) {
                    a[i][j] = k;
                    break;
                }
            }
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
