#include <bits/stdc++.h>
using namespace std;

string a[100000];

int main()
{
    int n;
    cin >> n;
    a[0] = "0";
    a[1] = "1";
    int inc = 2;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < inc; j++) {
            a[2*inc-1-j] = "1" + a[j];
        }
        for (int j = 0; j < inc; j++) {
            a[j] = "0" + a[j];
        }
        inc *= 2;
    }
    for (int i = 0; i < inc; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
