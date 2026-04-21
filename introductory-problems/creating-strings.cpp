#include <bits/stdc++.h>
using namespace std;

void create_string(vector<string> &res, map<char, int> &a, string str, int len)
{
    if (str.length() == len) {
        res.push_back(str);
        return;
    }
    for (char c = 'a'; c <= 'z'; c++) {
        if (a[c] > 0) {
            a[c] -= 1;
            create_string(res, a, str+c, len);
            a[c] += 1;
        }
    }
}

int main()
{
    map<char, int> a;
    vector<string> res;
    for (char c = 'a'; c <= 'z'; c++) {
        a[c] = 0;
    }
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        a[s[i]] += 1;
    }
    create_string(res, a, "", s.length());
    cout << res.size() << endl;
    for (auto it = res.begin(); it < res.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
