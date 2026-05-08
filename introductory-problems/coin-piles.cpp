#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    long int a, b, tmp, dif;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (b > a) {
            tmp = a;
            a = b;
            b = tmp;
        }
        dif = a-b;
        if (dif > b) {
            cout << "NO" << endl;
            continue;
        }
        else {
            a -= dif*2;
            if (a%3 != 0) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
