#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, flag;
    char min_char;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    string res = "";
    res += s[0][0];
    vector<pair<int, int>>  dig[2];
    flag = 0;
    dig[flag].push_back(pair<int, int> (0, 0));
    map<pair<int, int>, bool> exist;
    for (int i = 1; i <= min((n-1)*2-1, 4000); i++) {
        min_char = 'a';
        for (auto &it: dig[flag]) {
            exist[pair<int, int> (it.first+1, it.second)] = false;
            exist[pair<int, int> (it.first, it.second+1)] = false;
            if (it.first+1 < n) min_char = min(min_char, s[it.first+1][it.second]);
            if (it.second+1 < n) min_char = min(min_char, s[it.first][it.second+1]);
        }
        dig[(flag+1)%2].clear();
        for (auto &it: dig[flag]) {
            if (
                it.first+1 < n 
                && s[it.first+1][it.second] == min_char
                && !exist[pair<int, int> (it.first+1, it.second)]
            ) {

                dig[(flag+1)%2].push_back(pair<int, int> (it.first+1, it.second));
                exist[pair<int, int> (it.first+1, it.second)] = true;
            }
            if (
                it.second+1 < n
                && s[it.first][it.second+1] == min_char
                && !exist[pair<int, int> (it.first, it.second+1)]
            ) {
                dig[(flag+1)%2].push_back(pair<int, int> (it.first, it.second+1));
                exist[pair<int, int> (it.first, it.second+1)] = true;
            }
        }
        flag = (flag+1)%2;
        res += min_char;
    }
    if (n > 1) res += s[n-1][n-1];
    cout << res;
    return 0;
}
