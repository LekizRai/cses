#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int ub, k;
    long long int sum = n*(n+1)/2;
    if (sum%2 == 1) {
        cout << "NO";
    }
    else if (sum == 6) {
        cout << "YES" << endl << 1 << endl << 3 << endl << 2 << endl << "1 2";
    }
    else {
        sum = sum/2;
        ub = 0;
        k = 0;
        cout << "YES" << endl;
        for (long long int i = n; i >= 1; i--) {
            if (sum <= i) {
                k = sum;
                break;
            }
            else {
                sum = sum - i;
                ub = i;
            }
        }
        cout << ub-2 << endl;
        for (int i = 1; i <= ub-1; i++) {
            if (i != k) {
                cout << i << " ";
            }
        }
        cout << endl << n-ub+2 << endl << k << " ";
        for (int i = ub; i <= n; i++) {
            cout << i << " ";
        }
    }
    return 0;
}
