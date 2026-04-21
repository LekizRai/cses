#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int> a;
    map<char, int> c;
    string s = "ACGT";
    for (int i = 0; i < s.length(); i++) {
        a[s[i]] = 0;
        c[s[i]] = 0;
    }
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (i == 0) {
            c[s[i]] += 1;
        }
        else {
            if (s[i] != s[i-1]) {
                a[s[i-1]] = max(a[s[i-1]], c[s[i-1]]);
                c[s[i-1]] = 0;
                c[s[i]] = 1;
            }
            else {
                c[s[i]] += 1;
            }
        }
    }
    int res = c[s[s.length()-1]];
    s = "ACGT";
    for (int i = 0; i < s.length(); i++) {
        res = max(res, a[s[i]]);
    }
    cout << res;
    return 0;
}
