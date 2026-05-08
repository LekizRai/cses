#include <bits/stdc++.h>
using namespace std;


int count_path(string s, bool free[][9], int i, int j, int n)
{
    if (free[i+1][j] && free[i-1][j] && !free[i][j+1] && !free[i][j-1]) return 0;
    if (!free[i+1][j] && !free[i-1][j] && free[i][j+1] && free[i][j-1]) return 0;

    if (i == 7 && j == 1) {
        if (n == 48) return 1;
        return 0;
    }

    int res = 0;
    free[i][j] = false;
    if (s[n] == '?') {
        if (free[i+1][j]) {
            res += count_path(s, free, i+1, j, n+1);
        }
        if (free[i][j-1]) {
            res += count_path(s, free, i, j-1, n+1);
        }
        if (free[i-1][j]) {
            res += count_path(s, free, i-1, j, n+1);
        }
        if (free[i][j+1]) {
            res += count_path(s, free, i, j+1, n+1);
        }
    }
    else {
        if (s[n] == 'D') {
            if (free[i+1][j]) res += count_path(s, free, i+1, j, n+1);
        }
        else if (s[n] == 'L') {
            if (free[i][j-1]) res += count_path(s, free, i, j-1, n+1);
        }
        else if (s[n] == 'U') {
            if (free[i-1][j]) res += count_path(s, free, i-1, j, n+1);
        }
        else if (s[n] == 'R') {
            if (free[i][j+1]) res += count_path(s, free, i, j+1, n+1);
        }
    }
    free[i][j] = true;
    return res;
}

int main()
{
    string s;
    cin >> s;
    bool free[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            free[i][j] = false;
        }
    }
    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            free[i][j] = true;
        }
    }
    cout << count_path(s, free, 1, 1, 0);
    return 0;
}
