#include <bits/stdc++.h>
using namespace std;


void display_sequence(int start, int num)
{
    for (int i = start; i <= num; i++) {
        cout << i << " ";
    }
    for (int i = 1; i < start; i++) {
        cout << i << " ";
    }
}

int main()
{
    int t, n, a, b;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        if ((a == 0 && b != 0) || (a != 0 && b == 0)) {
            cout << "NO" << endl;
        }
        else if (a+b > n) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            for (int i = n; i > a+b; i--) {
                cout << i << " ";
            }
            for (int i = 1; i <= a+b; i++) {
                cout << i << " ";
            }
            cout << endl;
            for (int i = n; i > a+b; i--) {
                cout << i << " ";
            }
            display_sequence(a+1, a+b);
        }

    }
    return 0;
}
