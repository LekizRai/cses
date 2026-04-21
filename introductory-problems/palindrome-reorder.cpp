#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int> a;
    for (char c = 'A'; c <= 'Z'; c++) {
        a[c] = 0;
    }
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        a[s[i]] += 1;
    }
    int num_odd = 0;
    char odd_c = '.';
    for (char c = 'A'; c <= 'Z'; c++) {
        if (a[c]%2 == 1) {
            num_odd += 1;
            odd_c = c;
        }
    }
    if (num_odd > 1) {
        cout << "NO SOLUTION";
    }
    else {
        string res = "";
        for (char c = 'A'; c <= 'Z'; c++) {
            if (c != odd_c && a[c] > 0) {
                for (int i = 0; i < a[c]/2; i++) {
                    res += c;
                }
            }
        }
        string mid = "";
        if (odd_c != '.') {
            for (int i = 0; i < a[odd_c]; i++) {
                mid += odd_c;
            }
        }
        string tmp_res = res;
        reverse(res.begin(), res.end());
        cout << tmp_res + mid + res;
    }
    return 0;
}
