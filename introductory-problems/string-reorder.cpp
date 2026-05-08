#include <bits/stdc++.h>
using namespace std;


int main()
{
    int a[29], len, max_num;
    string s;
    cin >> s;
    for (int i = 0; i < 29; i++) {
        a[i] = 0;
    }
    for (int i = 0; i < int(s.length()); i++) {
        a[s[i]-'A'] += 1;
    }
    max_num = 0;
    len = int(s.length());
    for (int i = 0; i < 29; i++) {
        max_num = max(max_num, a[i]);
    }
    if (max_num >= (len+3)/2) {
        cout << -1;
        return 0;
    }
    char max_char, cur_char = 'a';
    for (int i = 0; i < int(s.length()); i++) {
        max_num = 0;
        for (int j = 0; j < 29; j++) {
            if (a[j] > max_num) {
                max_num = a[j];
                max_char = j+'A';
            }
        }
        if (max_num >= (len/2)+1) {
            cout << max_char;
            a[max_char-'A'] -= 1;
            cur_char = max_char;
            len -= 1;
        }
        else {
            for (int j = 0; j < 29; j++) {
                if (a[j] && j+'A' != cur_char) {
                    cout << char(j+'A');
                    a[j] -= 1;
                    cur_char = j+'A';
                    len -= 1;
                    break;
                }
            }
        }
    }
    return 0;
}
