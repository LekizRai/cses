#include <bits/stdc++.h>
using namespace std;

int count_strategy(bool reserved[][8], bool free_ldig[], bool free_rdig[], bool free_ve[], int n) {
    if (n == 8) {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < 8; i++) {
        if (!reserved[n][i] && free_ldig[n+i] && free_rdig[n-i+7] && free_ve[i]) {
            free_ldig[n+i] = false;
            free_rdig[n-i+7] = false;
            free_ve[i] = false;
            res += count_strategy(reserved, free_ldig, free_rdig, free_ve, n+1);
            free_ldig[n+i] = true;
            free_rdig[n-i+7] = true;
            free_ve[i] = true;
        }
    }
    return res;
}

int main()
{
    string s[8];
    bool free_ldig[16];
    bool free_rdig[16];
    bool free_ve[8];
    bool reserved[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            reserved[i][j] = false;
        }
    }
    for (int i = 0; i < 8; i++) {
        cin >> s[i];
        for (int j = 0; j < 8; j++) {
            if (s[i][j] == '*') {
                reserved[i][j] = true;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        free_ve[i] = true;
    }
    for (int i = 0; i < 16; i++) {
        free_ldig[i] = true;
        free_rdig[i] = true;
    }
    cout << count_strategy(reserved, free_ldig, free_rdig, free_ve, 0);
    return 0;
}
